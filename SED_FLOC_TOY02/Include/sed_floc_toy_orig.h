/*
** svn $Id: bio_toy.h 830 2017-01-24 21:21:11Z arango $
*******************************************************************************
** Copyright (c) 2002-2017 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options one-dimensional (vertical) Biology Toy.
**
** Application flag:   SED_TOY
** Input script:       ocean_sed_toy.in
**                     sediment.in
*/

#define ROMS_MODEL
#define SED_TOY
#define UV_ADV
#define UV_SADVECTION
#define UV_COR
#undef UV_QDRAG
#define DJ_GRADPS
#define SPLINES_VDIFF
#define SPLINES_VVISC
#undef TS_U3HADVECTION
#undef TS_C4VADVECTION
#define TS_MPDATA
#define SOLAR_SOURCE
#define NONLIN_EOS
#define SALINITY
#define AVERAGES
#define SOLVE3D

#undef LMD_MIXING
#ifdef LMD_MIXING
# define LMD_RIMIX
# define LMD_CONVEC
# define LMD_SKPP
# define LMD_BKPP
# define LMD_NONLOCAL
# define RI_SPLINES
#endif

#define SSW_BBL
#ifdef SSW_BBL
# define  SSW_CALC_UB
# define SSW_CALC_ZNOT
# define SSW_LOGINT
#endif

#define GLS_MIXING
#ifdef GLS_MIXING
# define KANTHA_CLAYSON
# define N2S2_HORAVG
# undef  CRAIG_BANNER
# undef  CHARNOK
# undef  ZOS_HSIG
# undef  TKE_WAVEDISS
#endif


#define BULK_FLUXES
#ifdef BULK_FLUXES
# define LONGWAVE
# define ANA_RAIN
#else
# define ANA_SMFLUX
# define ANA_STFLUX
#endif

#define ANA_SSFLUX
#define ANA_BSFLUX
#define ANA_BTFLUX
#define ANA_SPFLUX
#define ANA_BPFLUX

#define ANA_NUDGCOEF
/*
**  Sediment model options.
*/

#define SEDIMENT
#ifdef SEDIMENT
# define SUSPLOAD
# undef  BEDLOAD_SOULSBY
# undef  BEDLOAD_MPM
# define SED_DENS
# undef  COHESIVE_BED
# undef  BF_TCR
# undef  LINEAR_TCR
# undef  POWERLAW_TCR
# define MIXED_BED
# undef  SED_MORPH
# define SED_FLOCS
# undef  FLOC_TURB_DISS
# define FLOC_BBL_DISS
# define SED_DEFLOC
# define SED_TAU_CD_CONST
# undef  SED_TAU_CD_LIN
# undef  SED_BIODIFF
#endif

/*
**  Biological model options.
**  Undefined all of these
*/

#undef BIO_FENNEL
#undef  ECOSIM
#undef  NEMURO
#undef  NPZD_FRANKS
#undef  NPZD_IRON
#undef  NPZD_POWELL

#ifdef BIO_FENNEL
# define CARBON
# define DENITRIFICATION
# define BIO_SEDIMENT
# define DIAGNOSTICS_BIO
#endif
#undef CARBON

#if defined ECOSIM || defined BIO_FENNEL
# define ANA_SPFLUX
# define ANA_BPFLUX
# define ANA_CLOUD
#endif

#if defined NEMURO
# define HOLLING_GRAZING
# undef  IVLEV_EXPLICIT
# define ANA_SPFLUX
# define ANA_BPFLUX
#endif

#if defined NPZD_FRANKS || defined NPZD_POWELL
# define ANA_SPFLUX
# define ANA_BPFLUX
#endif

#if defined NPZD_IRON
# define ANA_SPFLUX
# define ANA_BPFLUX
# undef  IRON_LIMIT
# undef  IRON_RELAX
#endif

#if defined BULK_FLUXES || defined ECOSIM
# define ANA_CLOUD
# define PAPA_CLM
#endif
