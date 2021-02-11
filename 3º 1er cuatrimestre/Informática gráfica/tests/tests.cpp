#include <gtest/gtest.h>
#include "global/globals.hpp"
#include "global/tuplasg.hpp"
#include "mallas/cubo.hpp"
#include "malla.hpp"
#include "objply.hpp"
#include "obj_revolucion.hpp"
#include "src/escena.hpp"

class TuplaTest : public testing::Test
{
protected:
	Tupla<int, 3> tupla3i;
};

class MallaTest : public testing::Test
{
protected:
	Malla3D malla;
};

class CuboTest : public testing::Test
{
protected:
	Cubo cubo;
};

TEST_F (TuplaTest, UnaTuplaEsIgualAEllaMisma)
{
	EXPECT_EQ(tupla3i, tupla3i);
	EXPECT_EQ(*tupla3i, *tupla3i);
}

TEST_F (TuplaTest, DosTuplasConstruidasIgualSonIguales)
{
	Tupla3u tupla1 = Tupla3u(534, 5422, 5425);
	Tupla3u tupla2 = Tupla3u(534, 5422, 5425);

	EXPECT_EQ(tupla1, tupla2);
	EXPECT_EQ(*tupla1, *tupla2);
}

TEST (GlobalsTest, DosFloatsIgualesSonIguales)
{
	float a = 0.5436546354;
	float b = 0.5436546354;

	EXPECT_EQ(FloatEq(a,b), true);
}

TEST (EscenaTest, LosModosDeVisualizacionEmpiezanApagados)
{
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Ajedrez), false);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Lineas), false);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Puntos), false);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Solido), false);
}

TEST (EscenaTest, PuedoCambiarElModoAjedrez)
{
	ASSERT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Ajedrez), false);

	Escena::Instance()->ModificarVisualizacion(Visualizacion::Ajedrez);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Ajedrez), true);
	Escena::Instance()->ModificarVisualizacion(Visualizacion::Ajedrez);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Ajedrez), false);
}

TEST (EscenaTest, PuedoCambiarElModoAristas)
{
	ASSERT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Lineas), false);

	Escena::Instance()->ModificarVisualizacion(Visualizacion::Lineas);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Lineas), true);
	Escena::Instance()->ModificarVisualizacion(Visualizacion::Lineas);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Lineas), false);
}

TEST (EscenaTest, PuedoCambiarElModoPuntos)
{
	ASSERT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Puntos), false);

	Escena::Instance()->ModificarVisualizacion(Visualizacion::Puntos);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Puntos), true);
	Escena::Instance()->ModificarVisualizacion(Visualizacion::Puntos);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Puntos), false);
}

TEST (EscenaTest, PuedoCambiarElModoSolido)
{
	ASSERT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Solido), false);

	Escena::Instance()->ModificarVisualizacion(Visualizacion::Solido);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Solido), true);
	Escena::Instance()->ModificarVisualizacion(Visualizacion::Solido);
	EXPECT_EQ(Escena::Instance()->EstadoVisualizacion(Visualizacion::Solido), false);
}

TEST (PLYTest, AbreFicherosAcabenONoEnPuntoPLY)
{
	ObjPLY ply0("plys/ant.ply");
	ObjPLY ply1("plys/ant");
}

TEST (PLYTest, LosFicherosInexistentesLanzanUnaExcepcion)
{
	EXPECT_THROW(ObjPLY ply("esto va a fallar xD"), std::runtime_error);
}

TEST (PLYTest, LosFicherosNoPLYLanzanUnaExcepcion)
{
	EXPECT_THROW(ObjPLY ply("Makefile"), std::runtime_error);
}

TEST (PLYTest, LosFicherosPLYSinEndHeaderPetan)
{
	EXPECT_THROW(
		ObjPLY ply("plys/corruptos/sin_end_header.ply"),
		std::runtime_error
	);
}

TEST (PLYTest, LosFicherosPLYSinFormatoASCIIPetan)
{
	EXPECT_THROW(
		ObjPLY ply("plys/corruptos/sin_format_ascii.ply"),
		std::runtime_error
	);
}

TEST (PLYTest, PuedoCargarAnt)
{
	ObjPLY ply("plys/ant.ply");
}

TEST (PLYTest, PuedoCargarBeethoven)
{
	ObjPLY ply("plys/beethoven.ply");
}

TEST (PLYTest, PuedoCargarBigDodge)
{
	ObjPLY ply("plys/big_dodge.ply");
}

TEST (PLYTest, PuedoCargarLataPCUE)
{
	ObjPLY ply("plys/lata-pcue.ply");
}

TEST (PLYTest, PuedoCargarLataPINF)
{
	ObjPLY ply("plys/lata-pinf.ply");
}

TEST (PLYTest, PuedoCargarLataPSUP)
{
	ObjPLY ply("plys/lata-psup.ply");
}

TEST (PLYTest, PuedoCargarPeon)
{
	ObjPLY ply("plys/peon.ply");
}

TEST (ObjRevolucionTest, PuedoCargarUnObjRevolucionAPartirDeUnPLY)
{
	ObjRevolucion objr("plys/peon.ply", 50);
}

TEST (ObjRevolucionTest, LaRevolucionRedimensionaPorElNumeroDeIteracionesMasTapas)
{
	ObjRevolucion objr("plys/peon.ply", 100);
	EXPECT_EQ(objr.Vertices().size(), 11*100+2);
}

int main (int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
