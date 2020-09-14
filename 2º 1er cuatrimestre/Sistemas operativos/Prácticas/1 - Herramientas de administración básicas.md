# PRÁCTICA 1 - HERRAMIENTAS DE ADMINISTRACIÓN BÁSICAS

## 1.0 - PASOS PREVIOS E INFORMACIÓN INTRODUCTORIA

Para hacer estas prácticas en los laboratorios de la ETSIIT es necesario seguir los siguiente pasos:

> Autocargar imagen (POSIX)

```sh
#!/bin/sh
# Copiar la imagen comprimida al directorio temporal
cp /fenix/depar/lsi/UML/*.gz /tmp
# Descomprimir la imagen
cd /tmp && gunzip *.gz
# Ejecutar la imagen
./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m
```

Esto arrancará un sistema Fedora con el kernel 3.0.4 (en el momento de escritura de este documento el kernel más actual es 5.3.1).
El nombre de usuario del sistema es *root*, sin contraseña.

Todos los sitemas Linux comienzan con siete procesos en terminal [*tty*](https://wiki.archlinux.org/index.php/Getty) para iniciar sesión y trabajar en ellos.
Para navegar entre ellos se puede pulsar la combinación `<C-A-F1..7>`[^C-A-F] o `<C-A-[izq dch]>`[^izq dch].
En un entorno puramente tty (uno en el que no estén cargados [X](https://wiki.archlinux.org/index.php/Xorg) o [Wayland](https://wiki.archlinux.org/index.php/Wayland)).

## 1.1 - ADMINISTRACIÓN DE USUARIOS Y GRUPOS EN LINUX

### 1.1.1 - EL ADMINISTRADOR DEL SISTEMA: `root`

El administrador del sistema, o  *superuser*, es aquel que tiene **todos** los privilegios sobre el mismo.
Identificamos a este [usuario](https://wiki.archlinux.org/index.php/Users_and_groups) como `root`, perteneciente al grupo `root` y con directorio de usuario `/root`.
Debido a que tiene todos los privilegios sobre el sistema, puede hacer absolutamente cualquier cosa sobre el mismo.
Como advierte [`sudo`](https://wiki.archlinux.org/index.php/Sudo) la primera vez que se ejecuta para conseguir permisos `root`...:

```
We trust you have received the usual lecture from the local System Administrator. It usually boils down to these three things:

#1) Respect the privacy of others.

#2) Think before you type.

#3) With great power comes great responsibility.
```

Para conseguir permisos de root puede usarse la orden [`su`](https://wiki.archlinux.org/index.php/Su) o anteponer `sudo` a cualquier orden.
La ventaja de `sudo` es que nos permite adquirir permisos de administrador para una tarea en concreto sin poner en peligro el sistema en operaciones triviales.

```sh
whoami
# groctel

su
# [sudo] password for groctel:

whoami
# root

exit

whoami
# groctel

sudo whoami
# root

whoami
# groctel
```

### 1.1.2 - GESTIÓN DE USUARIOS

EN Linux, los usuarios tienen las siguientes propiedades:

- **Username:** Cadena de caracteres que representa el nombre de usuario.
- **User Identifier ([UID](https://wiki.archlinux.org/index.php/DeveloperWiki:UID_/_GID_Database)):** Entero que el sistema le asigna internamente para representarlo.
  - El UID de `root` es `0`.
- **Group Identifier ([GID](https://wiki.archlinux.org/index.php/DeveloperWiki:UID_/_GID_Database)):** Entero que el sistema le asigna para identificarlo como miembro de un [grupo de usuarios](https://wiki.archlinux.org/index.php/Users_and_groups).
  - **Grupo principal:** Grupo primario al que pertenece el usuario. Se almacena en `/etc/passwd`.
    - El GID del grupo principal de `root` es `0`.
  - **Grupos suplementarios:** Otros grupos a los que pertenecie el usuario. Se almacenan en `/etc/group`.

Estos son los ficheros que usa Linux para almacenar información sobre sus usuarios:

- **`/etc/group`:** Define los grupos del sistema y los usuarios que pertenecen a ellos.
- **`/etc/passwd`:** Almacena información sobre los usuarios del sistema.
- **`/etc/shadow`:** Guarda las contraseñas encriptadas de los usuarios e información sobre el envejecimiento de sus cuentas. 

### 1.1.3 - CREACIÓN DE CUENTAS DE USUARIO:

Se han de seguir los siguientes pasos para [crear un nuevo usuario](https://wiki.archlinux.org/index.php/Users_and_groups#User_management) en el sistema:

#### Decidir un nombre para la cuenta:

Debe ser un nombre descriptivo que lo diferencie del resto de usuarios.

#### Introudcir los datos del usuario en `/etc/passwd` y `/etc/group`

#### Crear el directorio `$HOME`[^$HOME] de dicho usuario:

Se debe establecer a dicho usuario como propietaro de su propio `$HOME`.

#### Crear ficheros de inicialización en `$HOME`:

Estos ficheros son `.$shell_profile` (ejecutado al iniciar sesión) y `.$shellrc` (ejecutado al abrir la shell) para la [shell](https://wiki.archlinux.org/index.php/Command-line_shell) `$shell` que utilize el sistema.
Debido a que lo más común es que esta shell sea `bash`, los ficheros se llaman `.bash_profile` y `.bashrc`.
Por defecto, estos ficheros se copian desde `/etc/skel`.
Estos ficheros (y otros ficheros `.*rc`) son perfectamente configurables por el usuario.
Por otro lado, `.$shell_logout` se ejecuta cuando el usuario cierra sesión.

#### Asignar una contraseña al usuario:

La orden `passwd $USER`[^$USER] nos permite asignar una contraseña al usuario `$USER`.

#### Establecer la shell del usuario:

Las shells usables del sistema se encuentran listadas en el fichero `/etc/shells`.
Puede cambiarse con la orden `chsh $shell`.
La shell por defecto es `/bin/sh`, aunque [puede no invocarse en algunos sistemas](https://askubuntu.com/questions/141928/what-is-the-difference-between-bin-sh-and-bin-bash).
Para evitar que un usuario entre al sistema se le puede asignar como shell `/bin/false` o `/sbin/nologin`, [cada una con un comportamiento diferente](https://unix.stackexchange.com/questions/10852/whats-the-difference-between-sbin-nologin-and-bin-false).
También puede asignarse un ejecutable como shell, de forma que la sesión del usuario queda restringida a dicho ejecutable.

#### Establecer otras facilidades:

Quota (vista más adelante), mail del usuario y permisos específicos.

#### Probar la cuenta nueva:

¡Ningún usuario debería entrar en una cuenta con errores garrafales de configuración!

Los pasos de creación de la cuenta se pueden abreviar con las órdenes `useradd`, que permite crear un usuario de forma automatizada:

```sh
# La opción -m de useradd crea el directorio $HOME automáticamente
useradd -m nuevousuario

passwd nuevouser
# New password: 
# Retype new password: 
# passwd: password updated successfully
```

La configuración predeterminada de creación de nuevos usuarios puede administrarse en `etc/default/useradd` y `/etc/login.defs`.

Podemos modificar las cuentas de usuario existentes con las siguientes órdenes:

- **`usermod`:** Modifica una cuenta de usuario existente.
- **`userdel`:** Elimina una cuenta de usuario.
- **`newusers`:** Crea cuentas de usuario a partir de un fichero con la sintaxis de `/etc/passwd`.

### 1.1.4 - PARÁMETROS DE CONFIGURACIÓN DE UNA CUENTA

Las cuentas de usuario pueden tener restricciones de tiempo (envejecimiento) tanto para la propia cuenta como para la contraseña.
Estos valores se almacenan en `/etc/shadow` y son los siguientes:
- **`changed`:** Fecha del último cambio de la contraseña.
- **`minlife`:** Número mínimo de días que deben pasar para cambiar la contraseña.
- **`maxlife`:** Número máximo de días que puede pasar el usuario con la misma contraseña.
- **`warn`:** Número de días que se debe informar al usuario antes de `maxlife`.
- **`inactive`:** Número de días pasado `maxlife` en los que se deshabilita la cuenta si no se ha cambiado la contraseña.
- **`expired`:** Fecha en la que la cuenta expira y se desactiva automáticamente.

Las órdenes `chage` y `passwd` permiten cambiar estos valores.

### 1.1.5 - GESTIÓN DE GRUPOS

Un grupo es un conjunto de usuarios que comparten recursos o ficheros del sistema.
Los grupos permiten dar o quitar acceso a múltiples usuarios de forma colectiva.
Tienen las siguientes propiedades:

- Nombre del grupo.
- Identificador o `GID`.
- Apartado en el ichero de configuración en `/etc/group`.

El fichero `/etc/group` presenta línea por línea todos los grupos disponibles en el sistema con la sintaxis `$grupo:x:GID:[$users]`[^corchetes].

Los grupos pueden administrarse con las siguientes órdenes:

- **`groupadd $group`:** Crea el grupo `$group`.
- **`groupmod $group`:** Modifica el grupo `$group`.
- **`groupdel $group`:** Elimina el grupo `$group`.
- **`newgrp $group`:** Lanza una shell con `$group`, convirtiéndolo en el grupo activo.
- **`gpasswd $group`:** Asigna una contraseña a `$group`.
- **`gpasswd -a $user $group`:** Añade `$user` a `$group`.
- **`groups [$user]`:** Informa de los grupos a los que pertenece el usuario activo o `$user`.
- **`id [$user]`:** Informa de los ID y los grupos a los que pertenece el usuario o `$user`.
- **`grpck`:** Verifica la integridad de `/etc/group`.

### 1.1.6 - USUARIOS Y GRUPOS ESPECIALES

Existen usuarios y grupos no asociados a personas físicas, sino que son propios del sistema operativo.
Estos usuarios y grupos son los siguientes:

**Usuarios:**

- **`root`:** Administrador del sistema.
- **Gestores de servicios:**
  - **`bin`:** [Mantenido por retrocompaibilidad](https://unix.stackexchange.com/questions/485505/what-is-the-bin-user-for).
  - **`daemon`:** Ejecuta procesos [en segundo plano](https://wiki.archlinux.org/index.php/Daemons).
  - **`lp`:** Envía ficheros a impresoras.
  - **`shutdown`:** Apaga la máquina.
  - **`sync`:** Sincroniza cachés y escribe a memoria secundaria.
- **Herramientas y utilidades:**
  - **`ftp`:** [File Trnasfer Protocol](https://en.wikipedia.org/wiki/File_Transfer_Protocol).
  - **`mail`:** Envía y recibe emails.
  - **`news`:** Agregador de contenido. (**TODO:** Confirmar)
- **Servicios del sistema:**
  - **[`mysql`](https://wiki.archlinux.org/index.php/MySQL):** Base de datos SQL.
  - **[`postgres`](https://wiki.archlinux.org/index.php/PostgreSQL):** Base de datos relacional de código abierto.
  - **[`xfs`](https://wiki.archlinux.org/index.php/XFS):** Sistema de archivos.
- **[`NFS`](https://wiki.archlinux.org/index.php/NFS):**
  - **`nobody`:** Usuario con el [mínimo número de permisos](https://unix.stackexchange.com/questions/186568/what-is-nobody-user-and-group).
  - **`nfsnobody:** Igual que `nobody` pero propio de `NFS`.

**[Grupos](https://wiki.archlinux.org/index.php/Users_and_groups#Group_list):**

- **Predeterminados:**
  - **`adm`:** Grupo de administración. 
  - **`bin`:** Mantenido por retrocompatibilidad.
  - **`daemon`:** Ejecuta procesos en segundo plano.
  - **`ftp`:** File Transfer Protocol.
  - **`lp`:** Envía ficheros a impresoras.
  - **`mail`:** Envía y recibe emails.
  - **`nobody`:** Grupo con el mínimo número de permisos.
  - **`root`:** Administrador del sistema.
  - **`sys`:** Administración de impresoras.
- **Específicos de dispositivos:**
  - **`audio`:** Acceso directo al hardware de sonido.
  - **`cdrom`:** Acceso al disco óptico. (**TODO:** Confirmar)
  - **`dialout`:** (**TODO:** Preguntar)
  - **`disk`:** Accede a discos no usados por otros grupos.
  - **`tty`:** Acceso a las tty.
  - **`video`:** Acceso al hardware de vídeo.
- **`kernel`:** Lee la memoria del kernel.
- **`users`:** Grupo al que pertenecen los usuarios por defecto.

## 1.2 - ORGANIZACIÓN DEL SISTEMA DE ARCHIVOS Y GESTIÓN BÁSICA DE ARCHIVOS

Los archivos que componen nuestro sistema se organizan en un árbol en el que la raíz es `/`, el llamado [directorio raíz](https://wiki.archlinux.org/index.php/Partitioning#/).
A partir de él se organizan el resto de directorios siguiendo el [estándar de jerarquía del sistema de archivos](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard).
Para referirnos a los ficheros podemos usar su **ruta absoluta**, p.e. `/home/groctel/.zshrc`, o su **ruta relativa**, `.zshrc` si estuviéramos en `~`.
Por otro lado, todos los archivos de los sistemas *nix[^*nix] siguen el estándar [MIME](https://en.wikipedia.org/wiki/MIME).



[^C-A-F]: La notación `<C-A-F1..7>` sigue dos convenciones.
`<C-X>` y `<A-X>` indican que se deben combinar las teclas `Ctrl` y `X` y las teclas `Alt` y `X` respectivamente.
`F1..7` indica que se pueden pulsar de la tecla `F1` a la `F7` inclusive.
La combinación `<C-X>` puede expresarse también como `^X` y `<A-X>`, como `M-X` (como ocurre en `nano`).
Por convención, estos apuntes usan `<C>` como la tecla `Ctrl`, `<A>` como `Alt` y `<M>` como `Meta` (la tecla `Windows` en muchos ordenadores.

[^izq dch]: Siguiendo expresiones regularles, `[izq dch]` indica que se pueden pulsar tanto la flecha izquierda como la derecha.

[^$HOME]: El atajo `$HOME` (equivalente a `~`) se refiere al directorio `/home/usuario` del usuario `usuario`.
Cada usuario tiene un `$HOME` distinto.

[^$USER]: `$USER` designa al usuario activo en la sesión actual.
Puedes comprobar tu usuario mediante la orden `echo $USER`.

[^corchetes]: La notación `[]` referida a sintaxis indica que lo que se encuentra en su interior es opcional.

[^*nix]: Referido a todos los [sistemas operativos basados en Unix](https://en.wikipedia.org/wiki/Unix).
