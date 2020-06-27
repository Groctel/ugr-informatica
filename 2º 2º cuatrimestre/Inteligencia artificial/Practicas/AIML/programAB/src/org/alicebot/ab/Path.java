package org.alicebot.ab;
import java.util.ArrayList;
/* Program AB Reference AIML 2.0 implementation
        Copyright (C) 2013 ALICE A.I. Foundation
        Contact: info@alicebot.org

        This library is free software; you can redistribute it and/or
        modify it under the terms of the GNU Library General Public
        License as published by the Free Software Foundation; either
        version 2 of the License, or (at your option) any later version.

        This library is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
        Library General Public License for more details.

        You should have received a copy of the GNU Library General Public
        License along with this library; if not, write to the
        Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
        Boston, MA  02110-1301, USA.
*/

/**
 * Linked list representation of Pattern Path and Input Path
 */
public class Path extends ArrayList<String>{
    public String word;
    public Path next;
    public int length;

    /**
     * Constructor - class has public members
     */
    private Path() {
        next = null;
        word = null;
        length = 0;
    }

    /**
     * convert a sentence (a string consisting of words separated by single spaces) into a Path
     *
     * @param sentence        sentence to convert
     * @return                sentence in Path form
     */
    public static Path sentenceToPath(String sentence) {
        sentence = sentence.trim();
        return arrayToPath(sentence.split(" "));
    }


    public static Path sentenceToPathDOS(String sentence) {
        sentence = sentence.trim();
        String aux=sentence;
        while(aux.contains("[")){

            int indice_a=aux.indexOf("[");
            int indice_c=aux.indexOf("]");
            String sub=sentence.substring(indice_a,indice_c);
            String sub_aux=sub;
            sub_aux=sub_aux.replace(" ","%");
            sentence=sentence.replace(sub,sub_aux);


            aux= aux.replaceFirst("\\[", " ");
            aux= aux.replaceFirst("]", " ");
            int a=0;

        }

        System.out.println(sentence);
        String palabras[]=sentence.split(" ");
        for (int i = 0; i < palabras.length; i++) {
            if(palabras[i].contains("%"))
                palabras[i]=palabras[i].replaceAll("%", " ");
                //palabras[i]=palabras[i].replaceAll("%", " ").replaceAll("\\[","").replaceAll("]","");
        }

        return arrayToPath(palabras);
    }

    /**
     * convert a sentence consider (),[] (a string consisting of words separated by single spaces) into a Path
     *
     * @param sentence        sentence to convert
     * @return                sentence in Path form
     */
    public static ArrayList<Path> sentenceToPathCorPar(String sentence) {
        sentence = sentence.trim();
        ArrayList<Path> paths=new ArrayList<Path>();

        ArrayList<String> sentences = procesarPatronCorPar(sentence);

        for (int i = 0; i < sentences.size(); i++) {
            paths.add( arrayToPath( sentences.get(i).trim().split(" "))  );
        }

        return paths;
    }

    /**
     * The inverse of sentenceToPath
     *
     * @param path           input path
     * @return               sentence
     */
    public static String pathToSentence (Path path) {
        String result="";
        for (Path p = path; p != null; p = p.next) {
            result = result+" "+p.word;
        }
        return result.trim();
       /* if (path == null) return "";
        else return path.word+" "+pathToSentence(path.next);*/
    }

    /**
     * convert an array of strings to a Path
     *
     * @param array     array of strings
     * @return          sequence of strings as Path
     */
    private static Path arrayToPath(String[] array) {
        Path tail = null;
        Path head = null;
        for (int i = array.length-1; i >= 0; i--) {
            head = new Path();
            head.word = array[i];
            head.next = tail;
            if (tail == null) head.length = 1;
            else head.length = tail.length + 1;
            tail = head;
        }
        return head;
        //return arrayToPath(array, 0);
    }

    /**
     * recursively convert an array to a Path
     *
     * @param array  array of strings
     * @param index  array index
     * @return       Path form
     */
    private static Path arrayToPath(String[] array, int index)  {
        if (index >= array.length) return null;
        else {
            Path newPath = new Path();
            newPath.word = array[index];
            newPath.next = arrayToPath(array, index+1);
            if (newPath.next == null) newPath.length = 1;
            else newPath.length = newPath.next.length + 1;
            return newPath;
        }
    }

    /**
     * print a Path
     */
    public void print() {
        String result = "";
        for (Path p = this; p != null; p = p.next) {
            result += p.word+",";
        }
        if (result.endsWith(",")) result = result.substring(0, result.length()-1);
        System.out.println(result);
    }



    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////MIO

    //saber si un ArrayList de cadenas contiene un caracter
    private static int contieneElCaracter(ArrayList<String> mejores,String caracter){

        int hay=-1;

        for (int i=0;i<mejores.size() && hay==-1;i++)
        {
            if(mejores.get(i).contains(caracter))
                hay=i;
        }
        return hay;
    }


    //parsear los corchetes, buscamos los corchetes y formamos tantos pattern como palabras tengan dentro
    private static ArrayList<String> parsearCorchetes(String pattern){

        ArrayList<String> mejores=new ArrayList<String>();
        ArrayList<String> aux_mejores=new ArrayList<String>();
        mejores.add(pattern);

        int indice=contieneElCaracter(mejores,"[");
        while(indice!=-1) {

            String patron = "";//nuevos patrones, patron2 no incluye el parentesis, patron si
            int ind_inicio = mejores.get(indice).indexOf("[");
            int ind_fin = mejores.get(indice).indexOf("]");

            //1. ver que palabras hay dentro de los corchetes
            String palabras = "";
            palabras += mejores.get(indice).substring(ind_inicio + 1, ind_fin);
            String palabrasSplit[];
            palabrasSplit = palabras.split(" ");

            //2. almacenamos las patrones para cada palabra incluida en los corchetes
            for (int i = 0; i < palabrasSplit.length; i++) {
                //inicializamos el patron
                patron = "";

                //nos quedamos hasta el primer corchete
                patron += mejores.get(indice).substring(0, ind_inicio);

                //nos quedamos con la parte interna del corchete
                patron += palabrasSplit[i];

                //nos quedamos desde el corchete de cierre hasta el final
                patron += mejores.get(indice).substring(ind_fin + 1, mejores.get(indice).length());

                //lo almacenamos los dos patrones, con parentesis y sin
                aux_mejores.add(patron);
            }

            //actualizamos mejores
            mejores.remove(indice); //nos quitamos el usado

            for (int i=0;i<aux_mejores.size();i++)
            {
                mejores.add(aux_mejores.get(i));
            }
            //reseteamos el auxiliar
            aux_mejores.clear();

            //System.out.println("");
            //actualizamos indice
            indice=contieneElCaracter(mejores,"[");
        }

        return mejores;
    }


    //parsear los parentesis, buscamos los parentesis y formamos dos pattern: uno con la palabra y otro sin ella
    private static ArrayList<String> parsearParentesis(String pattern){

        ArrayList<String> mejores=new ArrayList<String>();
        mejores.add(pattern);

        int indice=contieneElCaracter(mejores,"(");
        while(indice!=-1) {

            String patron="",patron2="";//nuevos patrones, patron2 no incluye el parentesis, patron si
            String actual=mejores.get(indice);

            if(actual.contains("(")){
                mejores.remove(indice); //nos quitamos el usado

                int ind_inicio=actual.indexOf("(");
                int ind_fin=actual.indexOf(")");

                //nos quedamos hasta el primer parentesis
                patron+=actual.substring(0,ind_inicio);
                patron2+=actual.substring(0,ind_inicio);

                //nos quedamos con la parte interna del parentesis
                patron+=actual.substring(ind_inicio+1,ind_fin);

                //nos quedamos desde el parentesis de cierre hasta el final
                patron+=actual.substring(ind_fin+1,actual.length());
                patron2+=actual.substring(ind_fin+1,actual.length());

                //lo almacenamos los dos patrones, con parentesis y sin
                mejores.add(patron);
                mejores.add(patron2);

            }

            //actualizamos indice
            indice=contieneElCaracter(mejores,"(");
        }

        return mejores;
    }


    //limpiamos de espacios multiples seguidos los patrones
    private static ArrayList<String> limpiarEspaciosSeguidos(ArrayList<String> patrones) {
        ArrayList<String> aux_aqui = new ArrayList<String>();

        for (int i = 0; i < patrones.size(); i++) {
            String actual = patrones.get(i);

            while (actual.indexOf("  ") != -1) {
                actual = actual.replaceAll("  "," ");
            }
            patrones.set(i, actual);

        }
        return patrones;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                  () y []

    // ()-> opcional, tendremos una nueva categoria con la palabra y otra sin ella
    // []-> posibles y obligatoria una, por cada palabra incluida añadimos una nueva categoria
    // tantas categorias como longitud([...])

    //en total tendremos un producto cartesiano de categorias -> longitud () * longitud []
    private static ArrayList<String> procesarPatronCorPar(String pattern)
    {
        ////////////////////////////////////////////////////////////////////
        // MIRAMOS LOS CORCHETES Y LOS PARENTESIS
        // si tiene el patron de ambos () []

        ArrayList<String> patrones=new ArrayList<String>();

        if(pattern.contains("(") && pattern.contains(")") &&  pattern.contains("[") && pattern.contains("]"))
        {

            //procesmos los corchetes

            //almacena los patrones ya sin corchetes
            ArrayList<String> aux_patrones=new ArrayList<String>();

            //si el pattern contiene los corchetes formamos n patrones nuevos:
            //n-> cada palabra dentro de los corchetes
            if(pattern.contains("[") && pattern.contains("]") )
            {
                aux_patrones=parsearCorchetes(pattern);
            }

            //una vez parseados los corchetes miramos los parentesis
            for (int i=0;i<aux_patrones.size();i++)
            {
                ArrayList<String> patronesDevueltos = parsearParentesis(aux_patrones.get(i));
                for (int j=0; j<patronesDevueltos.size();j++)
                    patrones.add(patronesDevueltos.get(j));
            }

        }
        //solo parentesis
        else if(pattern.contains("(") && pattern.contains(")") && !pattern.contains("[") && !pattern.contains("]") )
        {
            ArrayList<String> patronesDevueltos = parsearParentesis(pattern);
            for (int j=0; j<patronesDevueltos.size();j++)
                patrones.add(patronesDevueltos.get(j));

        }
        //solo corchetes
        else if(pattern.contains("[") && pattern.contains("]") && !pattern.contains("(") && !pattern.contains(")"))
        {
            patrones=parsearCorchetes(pattern);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //limpiamos de espacios multiples seguidos los patrones ya que se han generado al eliminar () o []
        patrones=limpiarEspaciosSeguidos(patrones);


        return patrones;
    }
    ////////////////////////// FIN MIO
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////



}
