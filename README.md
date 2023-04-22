# Servidor web en C con implementación de API Berkerly Sockets

### introduccion

En este proyecto se explora la aplicación de la capa de aplicación de la arquitectura
TCP/IP. Al respecto, se abordará desde el estudio del protocolo HTTP desde una
perspectiva de programación en red. Para esto se desarrollará e implementará un
servidor web.
En términos generales la función principal de un servidor web es la entrega de recursos
(páginas html, imágenes, archivos de estilos, etc) web a un cliente que lo solicita (p.ej.,
web browser). Para esto, tanto el cliente como el servidor se comunican a través de un
mismo protocolo que es HTTP.
De esta forma el objetivo final es desarrollar e implementar un servidor web denominado
Telematics Web Server – (TWS)) que soporte la versión HTTP/1.1
Este es un servidor web simple implementado en el lenguaje de programación C utilizando la librería de Berkerly Sockets. El servidor web puede manejar solicitudes HTTP GET, POST y HEAD en un archivo `index.html` en la carpeta `public` del servidor. 

## Requisitos previos

Antes de compilar y ejecutar este servidor web necesitaremos el servicio de nube AWS EC2 para el despligue, tambien asegúrate de tener instalada la librería de Beverly Sockets en tu sistema operativo. También es recomendable tener instalada la herramienta Postman o cualquier otro cliente HTTP para probar el servidor. Aqui te enseñamos todo!!
### Cómo iniciar una instancia EC2 en AWS y actualizar el sistema operativo

Este documento proporciona instrucciones paso a paso sobre cómo iniciar una instancia EC2 en AWS y actualizar su sistema operativo.

### Iniciar una instancia EC2

Para iniciar una instancia EC2 en AWS, siga estos pasos:

1. Inicie sesión en el Panel de Control de AWS.
2. Navegue hasta la sección de instancias EC2 haciendo clic en "Instancias EC2" en la sección "Servicios" del menú desplegable.
3. Haga clic en "Lanzar instancia" para comenzar el proceso de creación de una nueva instancia.
4. Seleccione la AMI que mejor se adapte a sus necesidades y haga clic en "Siguiente".
5. Seleccione el tipo de instancia que desea lanzar y haga clic en "Siguiente".
6. Configure los detalles de la instancia, como la red en la que desea lanzar la instancia, la configuración de seguridad y otros detalles importantes. Haga clic en "Siguiente" una vez que haya configurado estos detalles.
7. Configure el almacenamiento para su instancia. Puede seleccionar el tipo de almacenamiento que desea utilizar, así como el tamaño y la cantidad de discos que desea asignar a la instancia. Haga clic en "Siguiente" una vez que haya configurado estos detalles.
8. Configure las etiquetas para su instancia. Las etiquetas son útiles para identificar su instancia y organizarla dentro de su cuenta de AWS. Haga clic en "Siguiente" una vez que haya configurado estas etiquetas.
9. Revise todas las configuraciones de su instancia y haga clic en "Lanzar" para iniciar el proceso de lanzamiento de la instancia.

### Actualizar el sistema operativo

Una vez que haya lanzado su instancia, puede conectarse a ella utilizando una herramienta de conexión remota, como SSH. Una vez conectado, puede actualizar el sistema operativo de su instancia utilizando los comandos adecuados para el sistema operativo que esté utilizando.

### Instrucciones para instalar GCC en Linux

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

primero debemos clonar el repositorio, puede hacerlo con el siguiente comando:
         
     git clone <url del repositorio>
     
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
      
## Conclusiones

este servidor web simple implementado en C utilizando la librería de Berkerly Sockets es una buena opción para aquellos que buscan una solución ligera y personalizada para manejar solicitudes HTTP en un archivo index.html. Si bien es importante tener en cuenta los requisitos previos, como la instalación de la librería de Beverly Sockets y el uso de una instancia EC2 de AWS para el despliegue, una vez configurado y en ejecución, el servidor es fácil de probar y personalizar para adaptarse a las necesidades específicas del usuario.




