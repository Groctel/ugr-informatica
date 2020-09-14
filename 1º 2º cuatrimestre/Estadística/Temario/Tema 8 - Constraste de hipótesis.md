# CONSTRASTE DE HIPÓTESIS

## 1 - DEFINICIONES

- **Constraste de hipótesis:** Procedimiento estadístico mediante el cual se investiga la veracidad de una hipótesis sobre una característica desconocida de una población o conjunto de poblaciones.
  - **Constraste paramétrico:** Constraste cuyas afirmaciones se hacen en base al conocimiento de la función de probabilidad de una variable aleatoria sobre los parámetros de ésta (media, varianza, proporción, diferencia de medias, cociente de varianzas o diferencia de proporciones).
  - **Constraste no paramétrico:** Contraste cuyas afirmaciones no se hacen en base a la distribución de probabilidad, ya que se desconoce.
- **Hipótesis:** Afirmación cuya veracidad se comprueba a lo largo del experimento y que sirve de base para todos los procedimientos del mismo.
  - **Hipótesis nula $H_{0}$:** Hipótesis que se plantea en un problema de constraste. Se busca rechazarla para tener un resultado positivo.
  - **Hipótesis alternativa $H_{1}$:** Hipótesis contraria a la hipótesis nula.
- **Errores asociados al contraste:**

| **HIPÓTESIS NULA $H_{O}$** | **RECHAZO** | **NO RECHAZO** |
| :---: | :---: | :---: |
| **VERDADERA** | Error tipo I ($\alpha$)| Decisión correcta |
| **FALSA** | Decisión correcta | Error tipo II ($\beta$) |

- **Estadístico del test o de contraste:** Variable aleatoria con distribución de probabilidad conocida cuyos valores permiten tomar la decisión de aceptar o rechazar la hipótesis nula.
  - **Valor experimental del estadístico de contraste:** Valor concreto que toma el estadístico del test para la muestra escogida.
- **Región de rechazo:**
  - **Región crítica:**
  - **Regisón de aceptación:**
- **P-valor asociado a un constraste:**

## 2 - PASOS PARA LA REALIZACIÓN DE UN CONSTRASTE

- Fijar las hipótesis nula $H_{0}$ y alternativa $H_{1}$.
- Buscar el estadístico del test que bajo la hipótesis nula tenga un comportamiento conocido.
- Determinar la región crítica.
- Seleccionar una muestra de tamaño n para la cual el estadístico tome un valor experimental.
- Rechazar o no la hipótesis nula.

## 3 - CONSTRASTES PARAMÉTRICOS

### 3.1 - CONSTRASTE PARA LA MEDIA DE UNA POBLACIÓN NORMAL

<span style="font-size:1.5em">
	$T=\frac{
		\overline{x}-\mu_{0}
		}{
		\frac{S}{\sqrt{n}}
	}
	\rightarrow t_{n-1}$
</span>

### 3.2 - CONSTRASTE PARA LA VARIANZA

<span style="font-size:1.5em">
	$\chi^{2}=\frac{
		(n-1)S^{2}
		}{
		\sigma^{2}_{0}
	}
	\rightarrow \chi^{2}_{n-1}$
</span>

### 3.3 - CONTRASTE PARA LA PROPORCIÓN

<span style="font-size:1.5em">
	$Z=\frac{
		\widehat{p}-p_{0}
		}{\sqrt{\frac{
			p_{0}(1-p_{0})
			}{
			n
		}}
	}
	\rightarrow N(0; 1)$
</span>

### 3.4 - CONTRASTE PARA LA DIFERENCIA DE MEDIAS DE DOS POBLACIONES NORMALES

### 3.5 - CONTRASTE PARA EL COCIENTE DE VARIANZAS

<span style="font-size:1.5em">
	$F=\frac{
		S^{2}_{X}
		}{
		S^{2}_{Y}
	}
	\rightarrow F_{n_{X}-1;n_{Y}-1}$
</span>

### 3.6 - CONTRASTE PARA LA DIFERENCIA DE PROPORCIONES

<span style="font-size:1.5em">
	$Z=\frac{
		(\widehat{p}_{x}-\widehat{p}_{y})-p_{0}
		}{
		\sqrt{\frac{
			\widehat{p}_{x}(1-\widehat{p}_{x})
			}{
			n_{x}
		}
		+\frac{
			\widehat{p}_{y}(1-\widehat{p}_{y})
			}{
			n_{y}
		}}
	}
	\rightarrow N(0;1)$
</span>

## 4 - CONSTRASTES NO PARAMÉTRICOS

### 4.1 - CONSTRASTE $\chi^{2}$ DE INDEPENDENCIA

### 4.2 - CONSTRASTE DE BONDAD DE AJUSTE