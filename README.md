# Servidor web en C con implementación de API Beverly Sockets

Este es un servidor web simple implementado en el lenguaje de programación C utilizando la librería de Beverly Sockets. El servidor web puede manejar solicitudes HTTP GET, POST y HEAD en un archivo `index.html` en la carpeta `public` del servidor. 

## Requisitos previos

Antes de compilar y ejecutar este servidor web, asegúrate de tener instalada la librería de Beverly Sockets en tu sistema operativo. También es recomendable tener instalada la herramienta Postman o cualquier otro cliente HTTP para probar el servidor.

#### Instrucciones para instalar GCC en Linux

1. Abre la terminal en tu distribución de Linux.

2. Actualiza la lista de paquetes disponibles con el siguiente comando:

         sudo apt-get update
    
3. Instala el paquete `build-essential` que incluye GCC y otros programas necesarios para compilar código en C y C++:
    
        sudo apt-get install build-essential

4. Verifica la versión de GCC instalada en tu sistema con el siguiente comando:

        gcc --version
    
Si GCC se ha instalado correctamente, deberías ver información sobre la versión de GCC instalada en tu sistema.

## Estructura del proyecto

El repositorio contiene los siguientes archivos:

- **public/index.html**: Este es el archivo HTML que se muestra cuando se hace una solicitud GET a la raíz del servidor. Puedes modificar este archivo para incluir cualquier contenido que desees mostrar en tu servidor.
- **server.c**: Este es el archivo fuente principal del servidor web. Contiene el código fuente para manejar las solicitudes HTTP entrantes y enviar respuestas.
- **logWeb.log**: Este es el archivo de registro que se utiliza para registrar las solicitudes entrantes y las respuestas del servidor. El archivo de registro se crea automáticamente cuando se inicia el servidor y se escribe en él cada vez que se realiza una solicitud.

Es importante mencionar que la carpeta `public` debe contener cualquier otro archivo o recurso que desees servir desde el servidor, como archivos CSS o JavaScript. También puedes crear subdirectorios dentro de la carpeta `public` para organizar tu contenido. El servidor servirá cualquier archivo que se encuentre en la ruta solicitada, siempre y cuando esté dentro de la carpeta `public`.

## Compilación y ejecución del servidor

Para compilar el código fuente del servidor web, utiliza el siguiente comando en la terminal:

      gcc server.c -o server
      
Luego, para ejecutar el servidor, utiliza el siguiente comando en la terminal:

      ./server <PORT> logWeb.log public

Asegúrate de reemplazar `<PORT>` con el número de puerto que deseas utilizar para el servidor. Por ejemplo, si deseas utilizar el puerto 8080, debes ejecutar el servidor con el siguiente comando:

      ./server 8080 logWeb.log public
      

## Prueba del servidor

Una vez que el servidor esté en ejecución, puedes probarlo utilizando Postman o cualquier otro cliente HTTP. Para hacer una solicitud GET al servidor, abre tu navegador web y escribe la siguiente URL:

      http://<SERVER_IP>:<HTTP_PORT>/index.html  
      

Asegúrate de reemplazar `<SERVER_IP>` con la dirección IP del servidor y `<HTTP_PORT>` con el número de puerto en el que está ejecutándose el servidor.

## Ejemplo de solicitudes HTTP

A continuación se muestran algunos ejemplos de solicitudes HTTP que se pueden enviar al servidor, junto con sus respectivas respuestas:

### Solicitud GET

Solicitud:

      GET /index.html HTTP/1.1
      Host: localhost:8080     
            
Respuesta:
      HTTP/1.1 200 OK
      Content-Type: text/html

      <!DOCTYPE html>
      <html>
      <head>
        <title>My Web Server</title>
      </head>
      <body>
        <h1>Hello, World!</h1>
      </body>
      </html>
      ```
      ```




