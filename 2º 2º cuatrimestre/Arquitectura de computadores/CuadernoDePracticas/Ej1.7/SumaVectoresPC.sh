#!/bin/sh

: $((componentes = 65536))

while [ "$componentes" -lt 67108865 ]; do
	./SumaVectores "$componentes" && printf "\n"
	: $((componentes *= 2))
done
