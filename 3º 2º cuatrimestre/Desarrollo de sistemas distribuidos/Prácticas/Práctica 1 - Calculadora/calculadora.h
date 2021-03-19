/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CALCULADORA_H_RPCGEN
#define _CALCULADORA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct resultado_calculo {
	int err;
	union {
		int resultado;
	} resultado_calculo_u;
};
typedef struct resultado_calculo resultado_calculo;

struct suma_1_argument {
	int arg1;
	int arg2;
};
typedef struct suma_1_argument suma_1_argument;

struct resta_1_argument {
	int arg1;
	int arg2;
};
typedef struct resta_1_argument resta_1_argument;

struct producto_1_argument {
	int arg1;
	int arg2;
};
typedef struct producto_1_argument producto_1_argument;

struct cociente_1_argument {
	int arg1;
	int arg2;
};
typedef struct cociente_1_argument cociente_1_argument;

#define CALCULADORA_PROG 20000001
#define CALCULADORA_VER 1

#if defined(__STDC__) || defined(__cplusplus)
#define Suma 1
extern  resultado_calculo * suma_1(int , int , CLIENT *);
extern  resultado_calculo * suma_1_svc(int , int , struct svc_req *);
#define Resta 2
extern  resultado_calculo * resta_1(int , int , CLIENT *);
extern  resultado_calculo * resta_1_svc(int , int , struct svc_req *);
#define Producto 3
extern  resultado_calculo * producto_1(int , int , CLIENT *);
extern  resultado_calculo * producto_1_svc(int , int , struct svc_req *);
#define Cociente 4
extern  resultado_calculo * cociente_1(int , int , CLIENT *);
extern  resultado_calculo * cociente_1_svc(int , int , struct svc_req *);
extern int calculadora_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define Suma 1
extern  resultado_calculo * suma_1();
extern  resultado_calculo * suma_1_svc();
#define Resta 2
extern  resultado_calculo * resta_1();
extern  resultado_calculo * resta_1_svc();
#define Producto 3
extern  resultado_calculo * producto_1();
extern  resultado_calculo * producto_1_svc();
#define Cociente 4
extern  resultado_calculo * cociente_1();
extern  resultado_calculo * cociente_1_svc();
extern int calculadora_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_resultado_calculo (XDR *, resultado_calculo*);
extern  bool_t xdr_suma_1_argument (XDR *, suma_1_argument*);
extern  bool_t xdr_resta_1_argument (XDR *, resta_1_argument*);
extern  bool_t xdr_producto_1_argument (XDR *, producto_1_argument*);
extern  bool_t xdr_cociente_1_argument (XDR *, cociente_1_argument*);

#else /* K&R C */
extern bool_t xdr_resultado_calculo ();
extern bool_t xdr_suma_1_argument ();
extern bool_t xdr_resta_1_argument ();
extern bool_t xdr_producto_1_argument ();
extern bool_t xdr_cociente_1_argument ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CALCULADORA_H_RPCGEN */
