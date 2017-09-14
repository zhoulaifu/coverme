        #include "fdlibm.h"	/* must include FDLIBM's fdlibm.h */
        main()
        {
                double y0();
                _LIB_VERSION =  _IEEE_;
                printf("IEEE: y0(1e300) = %1.20e\n",y0(1e300));
                _LIB_VERSION = _XOPEN_;
                printf("XOPEN y0(1e300) = %1.20e\n",y0(1e300));
                _LIB_VERSION = _POSIX_;
                printf("POSIX y0(1e300) = %1.20e\n",y0(1e300));
                _LIB_VERSION = _SVID_;
                printf("SVID  y0(1e300) = %1.20e\n",y0(1e300));
                exit(0);
        }
