# Práctica 4 - Node.js

Tanto `npm` como `yarn` son perfectamente intercambiables para las instrucciones de instalación.
Yo he usado `yarn`, pero puedes usar `npm` sin problemas:

## Instalación

```sh
yarn install
```

## Ejecución

### Ejemplo 1: Hola mundo

```sh
yarn hola_mundo
```

Accede a `http://127.0.0.1:8080/` en tu navegador.

### Ejemplo 2: Calculadora

```sh
yarn calculadora
```

Accede a `http://127.0.0.1:8080/` en tu navegador y añade los siguientes elementos a la ruta:

- **Operación:** `sumar`, `restar`, `multiplicar` o `dividir`.
- **Operando1:** Cualquier número.
- **Operando2:** Cualquier número.

Por ejemplo:

```
http://127.0.0.1:8080/sumar/5/9
http://127.0.0.1:8080/dividir/523/2321
```
