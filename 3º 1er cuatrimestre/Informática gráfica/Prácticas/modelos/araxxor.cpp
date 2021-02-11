#include "modelos/araxxor.hpp"

Araxxor :: Araxxor () noexcept
:
	abdomen (new AbdomenAraxxor()),
	cabeza  (new CabezaAraxxor()),
	patas   {
		{
			new PataAraxxor(
				"plys/Araxxor/pata_derecha_0_femur.ply",
				"plys/Araxxor/pata_derecha_0_tibia.ply",
				"plys/Araxxor/pata_derecha_0_metatarso.ply",
				"plys/Araxxor/pata_derecha_0_tarso.ply",
				{14.0f, -46.4f, -53.3f}, {0.3f, 1.0f, 0.25f},
				{27.7f, 45.5f, -5.4f},   {1.0f, 0, 1.0f},
				{7.6f, 33.1f, -61.3f},   {1.0f, 0, 0},
				{1.5f, -17.0f, -30.9f},  {1.0f, 0, 0}
			),
			new PataAraxxor(
				"plys/Araxxor/pata_derecha_1_femur.ply",
				"plys/Araxxor/pata_derecha_1_tibia.ply",
				"plys/Araxxor/pata_derecha_1_metatarso.ply",
				"plys/Araxxor/pata_derecha_1_tarso.ply",
				{15.3f, -45.1f, -50.5f}, {0.3f, 1.0f, 0.25f},
				{35.5f, 40.7f, -21.8f},  {1.0f, 0, 1.0f},
				{41.7f, -5.6f, -46.2f},  {1.0f, 0, 1.0f},
				{9.1f, -38.5f, -15.7f},  {1.0f, -2.0f, -0.8f},
				M_PI/2
			),
			new PataAraxxor(
				"plys/Araxxor/pata_derecha_2_femur.ply",
				"plys/Araxxor/pata_derecha_2_tibia.ply",
				"plys/Araxxor/pata_derecha_2_metatarso.ply",
				"plys/Araxxor/pata_derecha_2_tarso.ply",
				{15.0f, -44.4f, -46.3f}, {0.3f, 1.0f, 0.25f},
				{39.6f, 45.2f, -6.6f},   {1.0f, 0, -1.0f},
				{47.1f, -15.5f, 34.7f},  {1.0f, 0, 0},
				{11.6f, -33.5f, 24.7f},  {1.0f, -2.0f, -0.8f}
			),
			new PataAraxxor(
				"plys/Araxxor/pata_derecha_3_femur.ply",
				"plys/Araxxor/pata_derecha_3_tibia.ply",
				"plys/Araxxor/pata_derecha_3_metatarso.ply",
				"plys/Araxxor/pata_derecha_3_tarso.ply",
				{11.7f, -41.8f, -39.7f}, {0.3f, 1.0f, 0.25f},
				{30.8f, 30.5f, 28.0f},   {1.0, 0, 0},
				{22.9f, -1.0f, 49.1f},   {-1.0f, 0, 0},
				{18.6f, -16.6f, 30.6f},  {1.0f, 0, 0},
				M_PI/2
			)
		},
		{
			new PataAraxxor(
				"plys/Araxxor/pata_izquierda_0_femur.ply",
				"plys/Araxxor/pata_izquierda_0_tibia.ply",
				"plys/Araxxor/pata_izquierda_0_metatarso.ply",
				"plys/Araxxor/pata_izquierda_0_tarso.ply",
				{-3.3f, -46.7f, -57.0f}, {0.3f, 1.0f, 0.25f},
				{-30.0f, 46.1f, -13.0f}, {1.0f, 0, -1.0f},
				{-29.9f, 4.5f, -59.9f},  {1.0f, 0, 1.0f},
				{16.7f, -36.8f, -6.6f},  {1.0f, 1.0f, -1.0f},
				M_PI/2
			),
			new PataAraxxor(
				"plys/Araxxor/pata_izquierda_1_femur.ply",
				"plys/Araxxor/pata_izquierda_1_tibia.ply",
				"plys/Araxxor/pata_izquierda_1_metatarso.ply",
				"plys/Araxxor/pata_izquierda_1_tarso.ply",
				{-3.8f, -43.6f, -52.9f},  {0.3f, 1.0f, 0.25f},
				{-44.4f, 43.5f, -10.7f},  {1.0f, 0, -1.0f},
				{-53.3f, -5.7f, -26.2f},  {0, 0, 1.0f},
				{-14.9f, -39.4f, -13.5f}, {-1.0f, 0, -1.0f}
			),
			new PataAraxxor(
				"plys/Araxxor/pata_izquierda_2_femur.ply",
				"plys/Araxxor/pata_izquierda_2_tibia.ply",
				"plys/Araxxor/pata_izquierda_2_metatarso.ply",
				"plys/Araxxor/pata_izquierda_2_tarso.ply",
				{-2.5f, -42.0f, -46.8f}, {0.3f, 1.0f, 0.25f},
				{-31.7f, 53.4f, -5.7f},  {1, 0, 1},
				{-57.9f, -12.2f, 13.3f}, {0, 0, 1.0f},
				{-6.6f, -39.0f, 5.6f},   {1.0f, -2.0f, -0.8f},
				M_PI/2
			),
			new PataAraxxor(
				"plys/Araxxor/pata_izquierda_3_femur.ply",
				"plys/Araxxor/pata_izquierda_3_tibia.ply",
				"plys/Araxxor/pata_izquierda_3_metatarso.ply",
				"plys/Araxxor/pata_izquierda_3_tarso.ply",
				{-4.7f, -41.7f, -40.6f}, {0.3f, 1.0f, 0.25f},
				{-47.2f, 41.4f, 26.1f},  {1, 0, 1},
				{-30.4f, -5.7f, 35.2f},  {1, 0, 1},
				{-24.0f, -26.8f, 29.0f}, {1.0f, 0, 0}
			)
		}
	}
{ }

Araxxor :: ~Araxxor () noexcept
{
	delete abdomen;
	delete cabeza;
	delete * patas[derecha];
	delete * patas[izquierda];
}

void Araxxor :: NuevoMovmiento (const MovimientosAraxxor m) noexcept
{
	movimiento = m;
}

Malla3D * Araxxor :: Cuerpo () const noexcept
{
	return abdomen->Cuerpo();
}

MovimientosAraxxor Araxxor :: Movimiento () const noexcept
{
	return movimiento;
}

Tupla3f Araxxor :: ColorSeleccion () const noexcept
{
	return abdomen->Cuerpo()->ColorSeleccion();
}

void Araxxor :: AplicarMaterial (Material * m) noexcept
{
	cabeza->AplicarMaterial(m);
	abdomen->AplicarMaterial(m);

	for (unsigned char i = 0; i < PATAS; i++)
	{
		patas[derecha][i]->AplicarMaterial(m);
		patas[izquierda][i]->AplicarMaterial(m);
	}
}

void Araxxor :: AplicarTextura  (Textura * nueva) noexcept
{
	abdomen->AplicarTextura(nueva);
	cabeza->AplicarTextura(nueva);

	for (unsigned char i = 0; i < PATAS; i++)
	{
		patas[derecha][i]->AplicarTextura(nueva);
		patas[izquierda][i]->AplicarTextura(nueva);
	}
}

void Araxxor :: Dibujar (
	const Dibujo dibujado,
	const bool ajedrez,
	const unsigned char color,
	const bool seleccion,
	const bool marcado
) noexcept
{
	abdomen->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
	cabeza->Dibujar(dibujado, ajedrez, color, seleccion, marcado);

	for (unsigned char i = 0; i < PATAS; i++)
	{
		patas[derecha][i]->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
		patas[izquierda][i]->Dibujar(dibujado, ajedrez, color, seleccion, marcado);
	}
}

void Araxxor :: Mover (const float factor) noexcept
{
	switch (movimiento)
	{
		case Abdomen:
			abdomen->Mover(factor);
		break;

		case Cabeza:
			cabeza->Mover(factor);
		break;

		case Femur:
			for (unsigned char i = 0; i < PATAS; i++)
			{
				patas[derecha][i]->RotarFemur(factor);
				patas[izquierda][i]->RotarFemur(factor);
			}
		break;

		case Tibia:
			for (unsigned char i = 0; i < PATAS; i++)
			{
				patas[derecha][i]->RotarTibia(factor);
				patas[izquierda][i]->RotarTibia(factor);
			}
		break;

		case Metatarso:
			for (unsigned char i = 0; i < PATAS; i++)
			{
				patas[derecha][i]->RotarMetatarso(factor);
				patas[izquierda][i]->RotarMetatarso(factor);
			}
		break;

		case Tarso:
			for (unsigned char i = 0; i < PATAS; i++)
			{
				patas[derecha][i]->RotarTarso(factor);
				patas[izquierda][i]->RotarTarso(factor);
			}
		break;

		default: break;
	}
}

void Araxxor :: NuevoColorSeleccion (const Tupla3f & color) noexcept
{
	abdomen->NuevoColorSeleccion(color);
	cabeza->NuevoColorSeleccion(color);

	for (unsigned char i = 0; i < PATAS; i++)
	{
		patas[derecha][i]->NuevoColorSeleccion(color);
		patas[izquierda][i]->NuevoColorSeleccion(color);
	}
}
