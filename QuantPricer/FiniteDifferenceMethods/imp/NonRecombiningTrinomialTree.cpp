//
//  NonRecombiningTrinomialTree.cpp
//  QuantPricer
//
//  Created by Swati Mital on 15/05/16.
//  Copyright (c) 2016 Swati Mital. All rights reserved.
//

#include "NonRecombiningTrinomialTree.h"

NonRecombiningTrinomialTree::NonRecombiningTrinomialTree(double S0, double sigma, double rf_rate, double dividend, double T, double steps)
: TrinomialTree(S0, sigma, rf_rate, dividend, T, steps)
{
    m_root = BuildUnderlyingTree(S0, NodeDir::Middle, 0);
    BreadthFirstTraversal(m_root);
}


boost::shared_ptr<Node<double, double>> NonRecombiningTrinomialTree::BuildUnderlyingTree(double val, NodeDir ndir, int tree_level)
{
    boost::shared_ptr<Node<double, double>> nd;
    
    if (tree_level > m_steps)
        return nullptr;
    
    if (ndir == NodeDir::Up) {
        nd = boost::make_shared<Node<double, double>>(m_up_factor*val, -1.0);
    } else if(ndir == NodeDir::Down) {
        nd = boost::make_shared<Node<double, double>>(m_down_factor*val, -1.0);
    } else {
        nd = boost::make_shared<Node<double, double>>(m_middle_factor*val, -1.0);
    }
    
    
    nd->middle = BuildUnderlyingTree(std::get<0>(nd->values), NodeDir::Middle, tree_level+1);
    nd->up = BuildUnderlyingTree(std::get<0>(nd->values), NodeDir::Up, tree_level+1);
    nd->down = BuildUnderlyingTree(std::get<0>(nd->values), NodeDir::Down, tree_level+1);
    
    return nd;
}
