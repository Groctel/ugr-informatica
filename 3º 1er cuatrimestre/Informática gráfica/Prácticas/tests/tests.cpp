#include <gtest/gtest.h>
#include "cubo.hpp"
#include "malla.hpp"
#include "tuplasg.hpp"

class TuplaTest : public testing::Test {
protected:
	tuplas::Tupla<int, 3> tupla3i;
};

class MallaTest : public testing::Test {
protected:
	Malla3D malla;
};

class CuboTest : public testing::Test {
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
	tuplas::Tupla3u tupla1 = tuplas::Tupla3u(534, 5422, 5425);
	tuplas::Tupla3u tupla2 = tuplas::Tupla3u(534, 5422, 5425);

	EXPECT_EQ(tupla1, tupla2);
	EXPECT_EQ(*tupla1, *tupla2);
}

/* TEST_F (TuplaTest, DosTuplasConDistintoTipoSonDiferentes) */
/* { */
/* 	tuplas::Tupla3i tupla1 {1, 2, 3}; */
/* 	tuplas::Tupla3u tupla2 {1, 2, 3}; */

/* 	EXPECT_NE(tupla1, tupla2); */
/* 	EXPECT_NE(*tupla1, *tupla2); */
/* } */

TEST_F (MallaTest, LosModosDeVisualizacionEmpiezanApagados)
{
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), false);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), false);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), false);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), false);
}

TEST_F (MallaTest, PuedoCambiarElModoAjedrez)
{
	ASSERT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), false);

	malla.ModificarVisualizacion(Visualizacion::Ajedrez, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), true);
	malla.ModificarVisualizacion(Visualizacion::Ajedrez, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), true);

	malla.ModificarVisualizacion(Visualizacion::Ajedrez, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), false);
	malla.ModificarVisualizacion(Visualizacion::Ajedrez, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), false);

	malla.ModificarVisualizacion(Visualizacion::Ajedrez);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), true);
	malla.ModificarVisualizacion(Visualizacion::Ajedrez);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Ajedrez), false);
}

TEST_F (MallaTest, PuedoCambiarElModoAristas)
{
	ASSERT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), false);

	malla.ModificarVisualizacion(Visualizacion::Lineas, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), true);
	malla.ModificarVisualizacion(Visualizacion::Lineas, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), true);

	malla.ModificarVisualizacion(Visualizacion::Lineas, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), false);
	malla.ModificarVisualizacion(Visualizacion::Lineas, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), false);

	malla.ModificarVisualizacion(Visualizacion::Lineas);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), true);
	malla.ModificarVisualizacion(Visualizacion::Lineas);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Lineas), false);
}

TEST_F (MallaTest, PuedoCambiarElModoPuntos)
{
	ASSERT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), false);

	malla.ModificarVisualizacion(Visualizacion::Puntos, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), true);
	malla.ModificarVisualizacion(Visualizacion::Puntos, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), true);

	malla.ModificarVisualizacion(Visualizacion::Puntos, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), false);
	malla.ModificarVisualizacion(Visualizacion::Puntos, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), false);

	malla.ModificarVisualizacion(Visualizacion::Puntos);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), true);
	malla.ModificarVisualizacion(Visualizacion::Puntos);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Puntos), false);
}

TEST_F (MallaTest, PuedoCambiarElModoSolido)
{
	ASSERT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), false);

	malla.ModificarVisualizacion(Visualizacion::Solido, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), true);
	malla.ModificarVisualizacion(Visualizacion::Solido, Bitset::Set);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), true);

	malla.ModificarVisualizacion(Visualizacion::Solido, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), false);
	malla.ModificarVisualizacion(Visualizacion::Solido, Bitset::Reset);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), false);

	malla.ModificarVisualizacion(Visualizacion::Solido);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), true);
	malla.ModificarVisualizacion(Visualizacion::Solido);
	EXPECT_EQ(malla.EstadoVisualizacion(Visualizacion::Solido), false);
}

int main (int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
