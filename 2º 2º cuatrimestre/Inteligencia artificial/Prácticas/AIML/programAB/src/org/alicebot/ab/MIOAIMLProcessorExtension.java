package org.alicebot.ab;
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

import com.sun.jndi.ldap.ext.StartTlsResponseImpl;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 * This is just a stub to make the contactaction.aiml file work on a PC
 * with some extension tags that are defined for mobile devices.
 */
public class MIOAIMLProcessorExtension implements AIMLProcessorExtension {

    public Set<String> extensionTagNames = Utilities.stringSet("writefile","readfile","readkeys","readset",
    "addtomap","removefrommap","modifymap","addtoset","removefromset");

    //public Set<String> extensionTagNames = Utilities.stringSet("writefile","readfile","readfileMap","writefileMap",
    //"addToMap","removeToMap","key","value","file");

    public Set <String> extensionTagSet() {
        return extensionTagNames;
    }

    public String recursEval(Node node, ParseState ps) {

        try {
            String nodeName = node.getNodeName();
            if(nodeName.equals("writefile"))
                return  writeFile(node,ps);
            else if(nodeName.equals("readfile"))
                return  readFile(node,ps);
            else if(nodeName.equals("addtomap"))
                return  addToMap(node,ps);
            else if(nodeName.equals("removefrommap"))
                return  removeFromMap(node,ps);
            else if(nodeName.equals("modifymap"))
                return  modifyMap(node,ps);
            else if(nodeName.equals("addtoset"))
                return  addToSet(node,ps);
            else if(nodeName.equals("removefromset"))
                return  removeFromSet(node,ps);
            else if(nodeName.equals("readset"))
                return  readSet(node,ps);
            else if(nodeName.equals("readkeys"))
                return  readKeys(node,ps);
            else return (AIMLProcessor.genericXML(node, ps));
        } catch (Exception ex) {
            ex.printStackTrace();
            return "";
        }
    }



    //obtenido de http://chuwiki.chuidiang.org/index.php?title=Lectura_y_Escritura_de_Ficheros_en_Java
    private String writeFile(Node node, ParseState ps) {
        String displayName = AIMLProcessor.evalTagContent(node, ps, null);
        String salida="";

        //System.out.println("subfix("+displayName+")");

        if(node.getAttributes().getLength()==1) {

            //obtenemos el nombre del atributo
            String predicatevarName = node.getAttributes().item(0).getNodeName();

            if(predicatevarName.equals("var") || predicatevarName.equals("name") ) {
                String predicado = "";

                //almacenamos el valor leido del fichero en la variable, dependiendo si es global o local
                //si es global
                if (predicatevarName.equals("name")) {

                    predicado = ps.chatSession.predicates.get(node.getAttributes().item(0).getNodeValue());
                    MagicBooleans.trace("Get predicate " + predicatevarName + " to " + salida + " in " + ps.leaf.category.inputThatTopic());
                }
                else if ( predicatevarName.equals("var") ){
                    predicado = ps.vars.get(node.getAttributes().item(0).getNodeValue());
                    MagicBooleans.trace("Get var " + predicatevarName + " to " + salida + " in " + ps.leaf.category.inputThatTopic());
                }


                FileWriter fichero = null;
                PrintWriter pw = null;

                try {
                    fichero = new FileWriter("./" + displayName);
                    pw = new PrintWriter(fichero);


                    ////////////////////////////////////////////////////////////////////////////////////////////////////

                    String[] palabras = predicado.split(" ");

                    for (int i = 0; i < palabras.length; i++)
                        pw.println(palabras[i]);


                    ////////////////////////////////////////////////////////////////////////////////////////////////////

                } catch (Exception e) {
                    e.printStackTrace();
                    salida = "No se ha podido escribir correctamente en el fichero " + displayName;
                } finally {
                    try {
                        // Nuevamente aprovechamos el finally para
                        // asegurarnos que se cierra el fichero.
                        if (null != fichero)
                            fichero.close();
                        salida = "Se ha escrito correctamente en el fichero " + displayName;

                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }
            }else salida="El atributo debe ser var o name";

        }
        else salida="No se ha encontrado la variable a escribir";

        return salida;
    }

    /**
     * set the value of an file.
     * Implements <readfile name="predicate"></fileread> and <fileread var="varname"></fileread>
     *
     * @param node     current XML parse node
     * @param ps       AIML parse state
     * @return         the result of the <readfile> operation
     */
    private String readFile(Node node, ParseState ps) {
        String displayName = AIMLProcessor.evalTagContent(node, ps, null);
        String salida="";
        //System.out.println("subfix("+displayName+")");

        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;

        try {
            // Apertura del fichero y creacion de BufferedReader para poder
            // hacer una lectura comoda (disponer del metodo readLine()).
            archivo = new File ("./"+displayName);
            fr = new FileReader (archivo);
            br = new BufferedReader(fr);

            // Lectura del fichero
            String linea;
            while((linea=br.readLine())!=null)
                salida+=linea+" ";


        }
        catch(Exception e){
            e.printStackTrace();
            salida+="No se ha podido leer correctamente el fichero "+displayName;
        }finally{
            // En el finally cerramos el fichero, para asegurarnos
            // que se cierra tanto si todo va bien como si salta
            // una excepcion.
            try{
                if( null != fr ){
                    fr.close();
                }
            }catch (Exception e2){
                e2.printStackTrace();
            }
        }

        //limpiamos la cadena leida
        salida = salida.replaceAll("(\r\n|\n\r|\r|\n)", " ");
        String value=salida.trim();

        //obtenemos el atributo de la etiqueta <readfile> para almacenar en variable "var" o "name" (local o global)
        if(node.getAttributes().getLength()==1 ) { // forzamos a que la etiqueta tenga un solo atributo

            //obtenemos el nombre del atributo
            String predicatevarName = node.getAttributes().item(0).getNodeName();


            //obtenemos el valor del atributo dependiendo del atributo usado(var|name), controlamos si los atributos están bien
            //definidos sino se lanza un mensaje
            String predicateName = "";
            String varName = "";

            if (predicatevarName.equals("name")) {
                varName = null;
                predicateName = node.getAttributes().item(0).getNodeValue();
            } else if (predicatevarName.equals("var")) {
                predicateName = null;
                varName = node.getAttributes().item(0).getNodeValue();
            }
            else{
                //los ponemos a null para que no se cree la variable (local o global)
                varName=null;
                predicateName=null;
                salida="usa (var=\"nombre\"|name=\"nombre\") como atributo de la etiqueta";
            }


            //almacenamos el valor leido del fichero en la variable, dependiendo si es global o local
            //si es global
            if (predicateName != null) {
                ps.chatSession.predicates.put(predicateName, salida);
                MagicBooleans.trace("Set predicate " + predicateName + " to " + salida + " in " + ps.leaf.category.inputThatTopic());
            }

            //si es local
            if (varName != null) {
                ps.vars.put(varName, salida);
                MagicBooleans.trace("Set var " + varName + " to " + value + " in " + ps.leaf.category.inputThatTopic());
            }

            //si en la sesion ya contiene un prononbre como set se redirige ese nombre a la salida
            if (ps.chatSession.bot.pronounSet.contains(predicateName)) {
                salida = predicateName;
            }
            //MagicBooleans.trace("in AIMLProcessor.set, returning: " + result);
        }
        else salida="no se ha encontrado variable donde guardar el fichero, usa (var=\"nombre\"|name=\"nombre\")";


        return salida;
    }





    private String addToMap(Node node, ParseState ps){


        ///////////////////////////////////////////////////////////////////
        NodeList childList = node.getChildNodes();

        String evalParser [] = new String[3];
        boolean aparece[]={false,false,false};

        for (int i = 0; i < childList.getLength(); i++) {
            Node n=childList.item(i);
            //if (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("file"))
            if (!n.getNodeName().equals("#comment") && !n.getNodeName().equals("#text") &&
               (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("name"))) {

                if(n.getNodeName().equals("key") && aparece[1]==false) {
                    evalParser[1] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[1]=true;
                }
                if(n.getNodeName().equals("value") && aparece[2]==false) {
                    evalParser[2] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[2]=true;
                }
                if(n.getNodeName().equals("name") && aparece[0]==false) {
                    evalParser[0] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[0]=true;
                }
            }// exactamente 3 evaluadas

        }

        //displayName=node.getFirstChild().getNodeValue()+displayName; // añado el texto que da lugar a esto que es key AND value TO map
        //////////////////////////////////////////////////////////////////

        //String displayName = AIMLProcessor.evalTagContent(node, ps, null); // descomentar las etiquetas key value file
                                                                            // comentar el bloque anterior lineas 433:443
        //String evalParser []= displayName.replaceAll("\t","").replaceAll("\n","").split(";");

        String result="";
        if(aparece[0]==true && aparece[1]==true && aparece[2]==true) {
           // if (!evalParser[0].equals("key AND value TO map"))
           //         result = null;
           // else{
                //insertamos en el map
                String file=evalParser[0];
                String key=evalParser[1].toUpperCase();
                String value=evalParser[2];

                try {

                    if(!ps.chatSession.bot.mapMap.get(file).containsKey(key)) {
                        ps.chatSession.bot.mapMap.get(file).put(key, value);
                        result += evalParser[0] + "\n" + evalParser[1] + " " + evalParser[2] + "\n" + "inserted correctly";

                        //GUARDAR EN FICHERO, CONCATENANDO
                        //writeFileMapSet(file, ps.chatSession.bot.mapMap.get(file), ps);
                        writeFileMapConcat(file,evalParser[1],value,ps);
                    }
                    else
                        result = "exist key " + key;

                }catch (Exception e){
                    result = "error in map";
                }
            //}



        }else{
            result="syntax error";
        }

        result="";
        return result;
    }

    private String removeFromMap(Node node, ParseState ps){

        ///////////////////////////////////////////////////////////////////
        NodeList childList = node.getChildNodes();

        String evalParser [] = new String[2];
        boolean aparece[]={false,false};

        for (int i = 0; i < childList.getLength(); i++) {
            Node n=childList.item(i);
            //if (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("file"))
            if (!n.getNodeName().equals("#comment") && !n.getNodeName().equals("#text") &&
                    (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("name"))) {

                if(n.getNodeName().equals("key") && aparece[1]==false) {
                    evalParser[1] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[1]=true;
                }
                if(n.getNodeName().equals("name") && aparece[0]==false) {
                    evalParser[0] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[0]=true;
                }
            }// exactamente 3 evaluadas

        }

        String result="";
        if(aparece[0] && aparece[1]) {
            //borramos en el map
            String file=evalParser[0];
            String key=evalParser[1].toUpperCase();

            try {
                if(ps.chatSession.bot.mapMap.get(file).containsKey(key)) {
                    ps.chatSession.bot.mapMap.get(file).remove(key);
                    result += evalParser[0] + " " + evalParser[1] + " deleted correctly";
                    //GUARDAR EN FICHERO
                    //writeFileMapSet(file, ps.chatSession.bot.mapMap.get(file), ps);
                    writeFileMapActualizandoFichero(file,key,null,ps,false);
                }else{
                    result = "not keys found"+key;
                }
            }catch (Exception e){
                result = "error in map";
            }

        }

        result="";
        return result;
    }


    private String modifyMap(Node node, ParseState ps){

        ///////////////////////////////////////////////////////////////////
        NodeList childList = node.getChildNodes();

        String evalParser [] = new String[3];
        boolean aparece[]={false,false,false};

        for (int i = 0; i < childList.getLength(); i++) {
            Node n=childList.item(i);
            //if (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("file"))
            if (!n.getNodeName().equals("#comment") && !n.getNodeName().equals("#text") &&
                    (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("name"))) {

                if(n.getNodeName().equals("key") && aparece[1]==false) {
                    evalParser[1] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[1]=true;
                }
                if(n.getNodeName().equals("value") && aparece[2]==false) {
                    evalParser[2] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[2]=true;
                }
                if(n.getNodeName().equals("name") && aparece[0]==false) {
                    evalParser[0] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[0]=true;
                }
            }// exactamente 3 evaluadas

        }

        String result="";
        if(aparece[1] && aparece[2] && aparece[0]) {
            //borramos en el map
            String file=evalParser[0];
            String key=evalParser[1].toUpperCase();
            String value=evalParser[2];

            try {
                if(ps.chatSession.bot.mapMap.get(file).containsKey(key)) {
                    ps.chatSession.bot.mapMap.get(file).put(key,value);
                    result += evalParser[0] + " " + evalParser[1] + " " + evalParser[2] + " modify correctly";
                    //writeFileMapSet(file, ps.chatSession.bot.mapMap.get(file), ps);
                    writeFileMapActualizandoFichero(file,key,value,ps,true);
                }
                else {
                    result = "error, key not found "+key;
                }
            }catch (Exception e){
                result = "error in map";
            }

        }

        result="";
        return result;
    }


    //cambiar contenido por el del SETPATTTERN
    private String addToSet(Node node, ParseState ps){
        ///////////////////////////////////////////////////////////////////
        NodeList childList = node.getChildNodes();

        String evalParser [] = new String[2];
        boolean aparece[]={false,false};

        for (int i = 0; i < childList.getLength(); i++) {
            Node n=childList.item(i);
            //if (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("file"))
            if (!n.getNodeName().equals("#comment") && !n.getNodeName().equals("#text") &&
                    (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("name"))) {

                if(n.getNodeName().equals("key") && aparece[1]==false) {
                    evalParser[1] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[1]=true;
                }

                if(n.getNodeName().equals("name") && aparece[0]==false) {
                    evalParser[0] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[0]=true;
                }
            }// exactamente 3 evaluadas

        }
        String result="";
        if(aparece[0] && aparece[1]) {
            //insertamos en el set
            String key=evalParser[1].toUpperCase();
            String file=evalParser[0];

            try {
                if(!ps.chatSession.bot.setMap.get(file).contains(key)) {
                    ps.chatSession.bot.setMap.get(file).add(key);
                    result += evalParser[0] + "\n" + evalParser[1] + "inserted correctly";

                    //GUARDAR EN FICHERO, CONCATENDADO
                    //writeFileMapSet(file, key, ps);
                    writeFileSetConcat(file,evalParser[1],ps);
                }
            }catch (Exception e){
                result = "error in set";
            }
        }
        else{
            result="syntax error";
        }

        result="";
        return result;
    }

    private String removeFromSet(Node node, ParseState ps){
        ///////////////////////////////////////////////////////////////////
        NodeList childList = node.getChildNodes();

        String evalParser [] = new String[2];
        boolean aparece[]={false,false};

        for (int i = 0; i < childList.getLength(); i++) {
            Node n=childList.item(i);
            //if (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("file"))
            if (!n.getNodeName().equals("#comment") && !n.getNodeName().equals("#text") &&
                    (n.getNodeName().equals("key") || n.getNodeName().equals("value") || n.getNodeName().equals("name"))) {

                if(n.getNodeName().equals("key") && aparece[1]==false) {
                    evalParser[1] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[1]=true;
                }

                if(n.getNodeName().equals("name") && aparece[0]==false) {
                    evalParser[0] = AIMLProcessor.evalTagContent(n, ps, null).replaceAll("\t", "").replaceAll("\n", "");
                    aparece[0]=true;
                }
            }// exactamente 3 evaluadas

        }
        String result="";
        if(aparece[0] && aparece[1]) {
            //borramos en el set
            String file=evalParser[0];
            String key=evalParser[1].toUpperCase();

            try {
                if(ps.chatSession.bot.setMap.get(file).contains(key)) {
                    ps.chatSession.bot.setMap.get(file).remove(key);
                    result += evalParser[0] + " " + evalParser[1] + " deleted correctly";

                    //GUARDAR EN FICHERO, CONCATENDADO
                    //writeFileMapSet(file, ps.chatSession.bot.setMap.get(file), ps);
                    writeFileSetActualizandoFichero(file,key,ps);
                }
            }catch (Exception e){
                result = "error in map";
            }

        }
        else result="syntax error";

        result="";
        return result;
    }



    private String readKeys(Node node, ParseState ps){
        String displayName = AIMLProcessor.evalTagContent(node, ps, null);
        try {

            AIMLMap map = ps.chatSession.bot.mapMap.get(displayName);
            return map.keySet().toString().substring(1,map.keySet().toString().length()).replaceAll(",","").replaceAll("]","").trim();
        }
        catch(Exception e) {
            return "not keys found";
        }
    }

    private String readSet(Node node, ParseState ps){

        String displayName = AIMLProcessor.evalTagContent(node, ps, null);
        try {

            AIMLSet set = ps.chatSession.bot.setMap.get(displayName);

            return set.toString().substring(1,set.toString().length()).replaceAll(",","").replaceAll("]","").trim();
        }
        catch(Exception e) {
            return "not keys found";
        }
    }




    //para actualizar el fichero map cuando se inserta un nuevo elemento
    private String writeFileMapSet(String name,String key, String value,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.maps_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            fichero = new FileWriter(f,false); // true para concatenar
            BufferedWriter bw = new BufferedWriter(fichero);

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            bw.write(key.toLowerCase()+":"+value+"\n");
            bw.close();

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }



    //para actualizar el fichero map cuando se elimina un componente
    private String writeFileMapSet(String name,AIMLMap map,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.maps_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            if(f.exists()) {
                fichero = new FileWriter(f);
                BufferedWriter bw = new BufferedWriter(fichero);

                ////////////////////////////////////////////////////////////////////////////////////////////////////

                for (String p : map.keySet()) {
                    bw.write(p.trim().toLowerCase() + ":" + map.get(p).trim() + "\n");
                }

                bw.close();
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }


    //Para actualizar el fichero sets cuando se elimina un elemento
    private String writeFileMapSet(String name,AIMLSet set,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.sets_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            if(f.exists()) {

                fichero = new FileWriter(f);
                BufferedWriter bw = new BufferedWriter(fichero);
                ////////////////////////////////////////////////////////////////////////////////////////////////////

                for (String p : set) {
                    bw.write(p.trim().toLowerCase() + "\n");
                }

                bw.close();

            }
            else{
                salida = "No se ha podido escribir correctamente en el fichero " + name;
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();

                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }


    //para acutalizar fichero sets cuando se inserta un nuevo elemento
    private String writeFileMapSet(String name,String key,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.sets_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            fichero = new FileWriter(f,true); // true para concatenar
            BufferedWriter bw = new BufferedWriter(fichero);

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            bw.write(key.toLowerCase().trim()+"\n");
            bw.close();

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }




    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    //para actualizar el fichero map cuando se inserta un nuevo elemento
    private String writeFileMapConcat(String name,String key, String value,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.maps_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            fichero = new FileWriter(f,true); // true para concatenar
            BufferedWriter bw = new BufferedWriter(fichero);

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            bw.write(key.toLowerCase()+":"+value+"\n");
            bw.close();

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }


    //para actualizar el fichero set cuando se inserta un nuevo elemento
    private String writeFileSetConcat(String name,String key,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.sets_path + "/" + name + ".txt");
        FileWriter fichero=null;

        try {
            fichero = new FileWriter(f,true); // true para concatenar
            BufferedWriter bw = new BufferedWriter(fichero);

            ////////////////////////////////////////////////////////////////////////////////////////////////////

            bw.write(key.toLowerCase()+"\n");
            bw.close();

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero)
                    fichero.close();
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }



    //para actualizar el fichero map cuando se elimina un componente actualizando el fichero
    private String writeFileMapActualizandoFichero(String name,String key,String value,ParseState ps,boolean modify) {

        String salida="";

        File f= new File(ps.chatSession.bot.maps_path + "/" + name + ".txt");
        FileWriter fichero=null;
        FileReader ficheroRead=null;

        try {

            if (f.exists()) {

                ficheroRead = new FileReader(ps.chatSession.bot.maps_path + "/" + name + ".txt");
                BufferedReader br = new BufferedReader(new FileReader(f));
                ////////////////////////////////////////////////////////////////////////////////////////////////////

                String entrada;
                String texto="";
                key=key.toLowerCase();

                if (!modify) {
                    while ((entrada = br.readLine()) != null) {
                        if (!entrada.contains(key)) {
                            texto+=entrada + "\n";
                        }
                    }
                } else {
                    while ((entrada = br.readLine()) != null) {
                        if (entrada.contains(key)) {
                            texto+=entrada.substring(0,entrada.indexOf(":"))+":"+value + "\n";
                        }else{
                            texto+=entrada + "\n";
                        }
                    }
                }


                br.close();

                fichero = new FileWriter(f);
                BufferedWriter bw = new BufferedWriter(fichero);

                bw.write(texto);

                bw.close();
            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero) {
                    fichero.close();
                    ficheroRead.close();
                }
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }


    //para actualizar el fichero map cuando se elimina un componente actualizando el fichero
    private String writeFileSetActualizandoFichero(String name,String key,ParseState ps) {

        String salida="";

        File f= new File(ps.chatSession.bot.sets_path + "/" + name + ".txt");
        FileWriter fichero=null;
        FileReader ficheroRead=null;

        try {
            if(f.exists()) {

                ficheroRead = new FileReader(f);
                BufferedReader br = new BufferedReader(ficheroRead);

                ////////////////////////////////////////////////////////////////////////////////////////////////////

                String entrada;
                String texto="";
                key=key.toLowerCase();

                while ((entrada = br.readLine()) != null) {
                    if (!entrada.contains(key)) {
                        texto+=entrada + "\n";
                    }
                }

                br.close();


                fichero = new FileWriter(f);
                BufferedWriter bw = new BufferedWriter(fichero);

                bw.write(texto);

                bw.close();

            }

            ////////////////////////////////////////////////////////////////////////////////////////////////////

        } catch (Exception e) {
            e.printStackTrace();
            salida = "No se ha podido escribir correctamente en el fichero " + name;
        } finally {
            try {
                // Nuevamente aprovechamos el finally para
                // asegurarnos que se cierra el fichero.
                if (null != fichero) {
                    fichero.close();
                    ficheroRead.close();
                }
                salida = "Se ha escrito correctamente en el fichero " + name;

            } catch (Exception e2) {
                e2.printStackTrace();
            }
        }

        return salida;
    }


}