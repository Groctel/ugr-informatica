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

TEST_F (MallaTest, ElModoAjedrezEmpiezaApagado)
{
	EXPECT_EQ(malla.Ajedrez(), false);
}

TEST_F (MallaTest, PuedoCambiarElModoAjedrez)
{
	ASSERT_EQ(malla.Ajedrez(), false);
	malla.Ajedrez(true);
	EXPECT_EQ(malla.Ajedrez(), true);
	malla.Ajedrez(true);
	EXPECT_EQ(malla.Ajedrez(), true);
	malla.Ajedrez(false);
	EXPECT_EQ(malla.Ajedrez(), false);
	malla.Ajedrez(false);
	EXPECT_EQ(malla.Ajedrez(), false);
}

TEST_F (MallaTest, ElModoAristasEmpiezaApagado)
{
	EXPECT_EQ(malla.Aristas(), false);
}

TEST_F (MallaTest, PuedoCambiarElModoAristas)
{
	ASSERT_EQ(malla.Aristas(), false);
	malla.Aristas(true);
	EXPECT_EQ(malla.Aristas(), true);
	malla.Aristas(true);
	EXPECT_EQ(malla.Aristas(), true);
	malla.Aristas(false);
	EXPECT_EQ(malla.Aristas(), false);
	malla.Aristas(false);
	EXPECT_EQ(malla.Aristas(), false);
}

TEST_F (MallaTest, ElModoPuntosEmpiezaApagado)
{
	EXPECT_EQ(malla.Puntos(), false);
}

TEST_F (MallaTest, PuedoCambiarElModoPuntos)
{
	ASSERT_EQ(malla.Puntos(), false);
	malla.Puntos(true);
	EXPECT_EQ(malla.Puntos(), true);
	malla.Puntos(true);
	EXPECT_EQ(malla.Puntos(), true);
	malla.Puntos(false);
	EXPECT_EQ(malla.Puntos(), false);
	malla.Puntos(false);
	EXPECT_EQ(malla.Puntos(), false);
}

TEST_F (MallaTest, ElModoSolidoEmpiezaApagado)
{
	EXPECT_EQ(malla.Solido(), false);
}

TEST_F (MallaTest, PuedoCambiarElModoSolido)
{
	ASSERT_EQ(malla.Solido(), false);
	malla.Solido(true);
	EXPECT_EQ(malla.Solido(), true);
	malla.Solido(true);
	EXPECT_EQ(malla.Solido(), true);
	malla.Solido(false);
	EXPECT_EQ(malla.Solido(), false);
	malla.Solido(false);
	EXPECT_EQ(malla.Solido(), false);
}

TEST_F (CuboTest, LosVerticesSonLasCoordenadasEnBinario)
{
	EXPECT_EQ(cubo.Vertice(0), tuplas::Tupla3f({0, 0, 0}));
	EXPECT_EQ(cubo.Vertice(1), tuplas::Tupla3f({0, 0, 1}));
	EXPECT_EQ(cubo.Vertice(2), tuplas::Tupla3f({0, 1, 0}));
	EXPECT_EQ(cubo.Vertice(3), tuplas::Tupla3f({0, 1, 1}));
	EXPECT_EQ(cubo.Vertice(4), tuplas::Tupla3f({1, 0, 0}));
	EXPECT_EQ(cubo.Vertice(5), tuplas::Tupla3f({1, 0, 1}));
	EXPECT_EQ(cubo.Vertice(6), tuplas::Tupla3f({1, 1, 0}));
	EXPECT_EQ(cubo.Vertice(7), tuplas::Tupla3f({1, 1, 1}));
	EXPECT_THROW(cubo.Vertice(8), std::out_of_range);
}

/* TEST_F (CuboTest, LasCarasVanEnSentidoAntohorarioArribaYAbajo) */
/* { */
/* 	EXPECT_EQ(cubo.Cara(0), tuplas::Tupla3i({0, 6, 2})); */
/* 	EXPECT_EQ(cubo.Cara(1), tuplas::Tupla3i({0, 4, 6})); */
/* 	EXPECT_THROW(cubo.Cara(12), std::out_of_range); */
/* } */

int main (int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
