class Solution {
 public:
  double PowerPos( double base, int exponent ) {
    double res = 1;
    while ( exponent > 0 ) {
      res *= base;
    }
    return res;
  }

  double NaivePower( double base, int exponent ) {
    double res = 0;
    if ( base == 0 ) return res;
    if ( exponent > 0 ) {
      if ( base > 0 ) {
        return PowerPos( base, exponent );
      }
      base = -base;
      return exponent % 2 ? PowerPos( base, exponent )
                          : -PowerPos( base, exponent );
    }

    if ( base > 0 ) {
      return 1 / PowerPos( base, exponent );
    }
    base = -base;
    return exponent % 2 ? 1 / PowerPos( base, exponent )
                        : -1 / PowerPos( base, exponent );
  }

  double BinExp( double base, long long exponent ) {
    // assume base > 0 and exponent > 0
    double res = 1;
    long long k = exponent;
    while ( k > 0 ) {
      // In the i-th iteration, the new base is base ^ i. If k & 1 == 1, the
      // factorization of base ^ exponent has a factor new_base
      if ( k & 1 ) {
        res *= base;
      }
      base *= base;
      k >>= 1;
    }
    return res;
  }

  double Power( double base, int exponent ) {
    if ( base == 0 ) return 0;
    if ( exponent > 0 ) {
      if ( base > 0 ) return BinExp( base, exponent );
      base = -base;
      return exponent % 2 == 0 ? BinExp( base, exponent )
                               : -BinExp( base, exponent );
    }

    long long e = -(long long)exponent;
    if ( base > 0 ) return 1 / BinExp( base, e );
    base = -base;
    return e % 2 == 0 ? 1 / BinExp( base, e ) : -1 / BinExp( base, e );
  }
};

