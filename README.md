# Default

Descripción del proyecto:

El proyecto consiste en la etapa de sensado de temperatura y nivel de batería para la OBC de un cubesat. El sistema también contará con control de servomotor mediante PWM lo que puede ser usado para el despliegue de antenas o paneles solares.

Objetivos Principales:

Inicio del sistema luego del reset en modo de sensado y transmisión.
Correcta conversion de niveles sensados.
Envío de la información mediante UART.
Accionamiento de PWM mediante pulsador (modo de prueba).
Emisión de alarma que indique modo de prueba activo.
Indicación del nivel de batería mediante la variación de frecuencia de parpadeo de un led.

Criterios de éxito:
El sistema se considerará exitoso si puede ejecutar las acciones citadas de manera correcta, sin generar reseteos o fallas.

Otros aspectos a considerar
-Especificaciones de Hardware: Agrega una descripción de los componentes de hardware en el README.md, mediante un diagramas de esquema y una guía básica para conectar sensores o actuadores.
-Generación de Documentación HTML con Doxygen: Usar Doxygen para generar la documentación HTML y colocarla en un directorio docs/ dentro del repositorio.

Consideraciones previas a la entrega:
Revisión, Ajustes Finales y Preparación para la Entrega
Revisión de Código y Documentación: Revisar el código para asegurar que todos los comentarios y la documentación estén completos y sean claros.
Limpieza y Confirmación del Repositorio: Asegurar de que el README.md, INSTALL.md, y otros archivos estén actualizados y claros. Verificar que el flujo CI/CD esté funcionando sin errores.

Preparación Final del Proyecto: Hacer una última revisión del Wiki para ver si todo está documentado y actualizado. Realizar una última prueba de compilación y verificación de funcionamiento del prototipo.
