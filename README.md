# ugr-informatica

Apuntes y material del Grado en Ingeniería Informática en la UGR.

## Submódulos

Este repositorio contiene submódulos, por lo que es necesario clonarlo y actualizarlo con las siguientes órdenes:

```sh
git clone --recurse-submodules
git pull  --recurse-submodules
```

## Compilación

Estos apuntes están diseñados para ser compilados en Linux y presumen una instalación completa y actualizada de [LaTeX](https://www.latex-project.org/).
Los apuntes utilizan [aqademia](https://github.com/Groctel/aqademia), una plantilla de LaTeX de elaboración propia.
Puedes instalarla en tu directorio `~/texmf` a mano o mediante la orden `make aqademia`, que clonará o actualizará la plantilla para compilar siempre con la última versión de la misma.
La receta principal del `Makefile` (`all`) actualiza la plantilla automáticamente cada vez que se compila, por lo que no es necesario actualizar manualmente.
Para compilar sin actualizar la plantilla, ejecuta `make build`.

Cada cuatrimestre y asignatura están identificados por una receta.
Los cuatrimestres siguen todos la expresión `c[1-4][1-2]`, siendo el primer dígito el curso y el segundo, el cuatrimestre en sí.
Las recetas de las asignaturas siguen todas su propio código **en minúsculas**.
Dichos códigos pueden consultarse en la declaración de variables del `Makefile` o pueden ser recuperados por las funciones de autocompletar de la shell.

## Obituario

El 5 de agosto de 2020 me levanté con un proyecto: ¡Reformar el repositorio para hacer más fácil trabajar con él!
Durante media hora estuve arreglando tranquilamente la nueva rama AC, que creé pocos minutos antes del desastre.

—Bien, ya tengo dos ramas, voy a verlas en GitHub—pensé.

Y así, según entraba a GitHub, vi que me habían hecho un merge.

—¡Oh! ¡Qué ilusión!—me dije.—Bueno, ya puedo borrar ese repo.

Y así, abrí éste repositorio para consultarlo y el otro para borrarlo.
Tabulación de pestañas, acceso a las opciones.
¡Zona peligrosa!
¿Está seguro que desea borrar el repositorio?
Por favor, introduzca el nombre del mismo.
Mas mi pereza, no, mi arrogancia me sugiere copiar y pegarlo.
Introduzca la contraseña.
Gracias, gestor de contraseñas por facilitarme la tarea.
"Se ha borrado con éxito ugr-informatica", reza un cartel al inicio de la página.
En ese momento mi cerebro se sobrecalienta.
He perdido mis estrellitas.

Moraleja de la historia:

**No os toméis a la ligera el borrado de un repositorio.
No os emabarquéis en operaciones potencialmente destructivas sin haberlo preparado todo.**
En este caso, el proyecto no era muy grande, pero mi error podría haber sido catastrófico en cualquier otro caso.
Por mi parte, ya he aprendido con el susto, el [onosegundo](https://www.youtube.com/watch?v=X6NJkWbM1xk).
Agradezco que sus consecuencias no hayan sido extremas.
