#ifndef dspcore_h
#define dspcore_h
#include "../core/options.h"

/* definition to expand macro then apply to pragma message */
#define VALUE_TO_STRING(x) #x
#define VALUE(x) VALUE_TO_STRING(x)
#define VAR_NAME_VALUE(var) #var "="  VALUE(var)

//#pragma message(VAR_NAME_VALUE(DSP_MODEL))

#if DSP_MODEL==DSP_DUMMY
  #define DUMMYDISPLAY
#elif DSP_MODEL==DSP_NV3041A
  #include "displayNV3041A.h"
#endif

//extern DspCore dsp;

#endif
