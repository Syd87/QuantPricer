//
//  BrownianMotionMethod.h
//  QuantPricer
//
//  Created by Swati Mital on 29/08/16.
//  Copyright (c) 2016 Swati Mital. All rights reserved.
//

#ifndef QuantPricer_BrownianMotionMethod_h
#define QuantPricer_BrownianMotionMethod_h

#include "ICharacteristicFunctionMethod.h"

#include <vector>
#include <complex>


namespace QuantPricer
{
    namespace CharacteristicFunctionMethods
    {
        class BrownianMotionMethod : public ICharacteristicFunctionMethod
        {
        public:
            BrownianMotionMethod(double sigma,
                                double St,
                                double rf_rate, 
                                double dividend,
                                double time_to_maturity);
            virtual ~BrownianMotionMethod() {}
            std::complex<double> CharacteristicFunction(std::complex<double> u);
            
        private:
            double m_sigma;
            double m_St;
            double m_rf_rate, m_time_to_maturity, m_dividend;
        };
    }
}


#endif
