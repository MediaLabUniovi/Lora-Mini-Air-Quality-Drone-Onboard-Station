<div align="right">

[![english](https://raw.githubusercontent.com/stevenrskelton/flag-icon/master/png/16/country-4x3/gb.png)](./README.md) | [![spanish](https://raw.githubusercontent.com/stevenrskelton/flag-icon/master/png/16/country-4x3/es.png)](./README_ES.md)

</div>

<div align="center">

# MINI ESTACIÓN DE CALIDAD DEL AIRE CONECTADA POR LORA A BORDO DE UN DRONE

[![made-for-VSCode](https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg)](https://code.visualstudio.com/) [![Build with PlatformIO](https://img.shields.io/badge/build%20with-PlatformIO-orange?logo=data%3Aimage%2Fsvg%2Bxml%3Bbase64%2CPHN2ZyB3aWR0aD0iMjUwMCIgaGVpZ2h0PSIyNTAwIiB2aWV3Qm94PSIwIDAgMjU2IDI1NiIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJ4TWlkWU1pZCI+PHBhdGggZD0iTTEyOCAwQzkzLjgxIDAgNjEuNjY2IDEzLjMxNCAzNy40OSAzNy40OSAxMy4zMTQgNjEuNjY2IDAgOTMuODEgMCAxMjhjMCAzNC4xOSAxMy4zMTQgNjYuMzM0IDM3LjQ5IDkwLjUxQzYxLjY2NiAyNDIuNjg2IDkzLjgxIDI1NiAxMjggMjU2YzM0LjE5IDAgNjYuMzM0LTEzLjMxNCA5MC41MS0zNy40OUMyNDIuNjg2IDE5NC4zMzQgMjU2IDE2Mi4xOSAyNTYgMTI4YzAtMzQuMTktMTMuMzE0LTY2LjMzNC0zNy40OS05MC41MUMxOTQuMzM0IDEzLjMxNCAxNjIuMTkgMCAxMjggMCIgZmlsbD0iI0ZGN0YwMCIvPjxwYXRoIGQ9Ik0yNDkuMzg2IDEyOGMwIDY3LjA0LTU0LjM0NyAxMjEuMzg2LTEyMS4zODYgMTIxLjM4NkM2MC45NiAyNDkuMzg2IDYuNjEzIDE5NS4wNCA2LjYxMyAxMjggNi42MTMgNjAuOTYgNjAuOTYgNi42MTQgMTI4IDYuNjE0YzY3LjA0IDAgMTIxLjM4NiA1NC4zNDYgMTIxLjM4NiAxMjEuMzg2IiBmaWxsPSIjRkZGIi8+PHBhdGggZD0iTTE2MC44NjkgNzQuMDYybDUuMTQ1LTE4LjUzN2M1LjI2NC0uNDcgOS4zOTItNC44ODYgOS4zOTItMTAuMjczIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzJzLTEwLjMyIDQuNjItMTAuMzIgMTAuMzJjMCAzLjc1NSAyLjAxMyA3LjAzIDUuMDEgOC44MzdsLTUuMDUgMTguMTk1Yy0xNC40MzctMy42Ny0yNi42MjUtMy4zOS0yNi42MjUtMy4zOWwtMi4yNTggMS4wMXYxNDAuODcybDIuMjU4Ljc1M2MxMy42MTQgMCA3My4xNzctNDEuMTMzIDczLjMyMy04NS4yNyAwLTMxLjYyNC0yMS4wMjMtNDUuODI1LTQwLjU1NS01Mi4xOTd6TTE0Ni41MyAxNjQuOGMtMTEuNjE3LTE4LjU1Ny02LjcwNi02MS43NTEgMjMuNjQzLTY3LjkyNSA4LjMyLTEuMzMzIDE4LjUwOSA0LjEzNCAyMS41MSAxNi4yNzkgNy41ODIgMjUuNzY2LTM3LjAxNSA2MS44NDUtNDUuMTUzIDUxLjY0NnptMTguMjE2LTM5Ljc1MmE5LjM5OSA5LjM5OSAwIDAgMC05LjM5OSA5LjM5OSA5LjM5OSA5LjM5OSAwIDAgMCA5LjQgOS4zOTkgOS4zOTkgOS4zOTkgMCAwIDAgOS4zOTgtOS40IDkuMzk5IDkuMzk5IDAgMCAwLTkuMzk5LTkuMzk4em0yLjgxIDguNjcyYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDkgMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OXoiIGZpbGw9IiNFNTcyMDAiLz48cGF0aCBkPSJNMTAxLjM3MSA3Mi43MDlsLTUuMDIzLTE4LjkwMWMyLjg3NC0xLjgzMiA0Ljc4Ni01LjA0IDQuNzg2LTguNzAxIDAtNS43LTQuNjItMTAuMzItMTAuMzItMTAuMzItNS42OTkgMC0xMC4zMTkgNC42Mi0xMC4zMTkgMTAuMzIgMCA1LjY4MiA0LjU5MiAxMC4yODkgMTAuMjY3IDEwLjMxN0w5NS44IDc0LjM3OGMtMTkuNjA5IDYuNTEtNDAuODg1IDIwLjc0Mi00MC44ODUgNTEuODguNDM2IDQ1LjAxIDU5LjU3MiA4NS4yNjcgNzMuMTg2IDg1LjI2N1Y2OC44OTJzLTEyLjI1Mi0uMDYyLTI2LjcyOSAzLjgxN3ptMTAuMzk1IDkyLjA5Yy04LjEzOCAxMC4yLTUyLjczNS0yNS44OC00NS4xNTQtNTEuNjQ1IDMuMDAyLTEyLjE0NSAxMy4xOS0xNy42MTIgMjEuNTExLTE2LjI4IDMwLjM1IDYuMTc1IDM1LjI2IDQ5LjM2OSAyMy42NDMgNjcuOTI2em0tMTguODItMzkuNDZhOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTkgOS4zOTggOS4zOTkgOS4zOTkgMCAwIDAgOS40IDkuNCA5LjM5OSA5LjM5OSAwIDAgMCA5LjM5OC05LjQgOS4zOTkgOS4zOTkgMCAwIDAtOS4zOTktOS4zOTl6bS0yLjgxIDguNjcxYTIuMzc0IDIuMzc0IDAgMSAxIDAtNC43NDggMi4zNzQgMi4zNzQgMCAwIDEgMCA0Ljc0OHoiIGZpbGw9IiNGRjdGMDAiLz48L3N2Zz4=)](https://platformio.org/)

## Proyecto basado en: [alexcorvis84/mini-lora-weatherstation](https://github.com/alexcorvis84/mini-lora-weatherstation)

</div>

___

<div align="justify">

## Índice
- [Introducción](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#introducci%C3%B3n-leftwards_arrow_with_hook)
- [Funciones principales](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-caracter%C3%ADsticas-principales-leftwards_arrow_with_hook-)
- [Lista de componentes](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-lista-de-componentes-leftwards_arrow_with_hook-)
- [Lista de conexiones](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-lista-de-conexiones-leftwards_arrow_with_hook-)
- [Flujograma (¡Simplificado!)](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-flujograma-simplificado-leftwards_arrow_with_hook-)
- [Archivos de código](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#archivos-de-c%C3%B3digo-leftwards_arrow_with_hook)
- [Experimento de despliegue](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-experimento-de-despliegue-leftwards_arrow_with_hook-)
- [Licencia](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-licencia-leftwards_arrow_with_hook-)
- [Contacto](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#-contacto-leftwards_arrow_with_hook-)

</div>

___

<div align="justify">

## Introducción [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice)

Como parte de mi Trabajo de Fin de Grado sobre drones y sensorización, en Medialab_ LPWAN, se me dio a conocer la tecnología de LoRaWAN. Con ella, entendí rápidamente el potencial de trabajar en un sensor de calidad de aire que montar en un drone de _long range_ para ser usado como plataforma móvil y medir a kilómetros de distancia atmósferas hostiles en caso de accidente donde fuese peligroso enviar a un equipo de personas. Como resultado, nació el sensor _on-board_ que os voy a mostrar como un nodo conectado por LoRa, sincronizable con [The Things Network](https://www.thethingsnetwork.org/), que montarle al drone que construí sin que la cobertura fuese un factor limitante.

</div>

<div align="center">
  <img src="https://github.com/medialablpwan/droneloraminiairqualitystation/blob/main/pics/photo_5976817429474556872_y.jpg" width="600"  style="margin: 10px;"/>
</div>
<br/>

<p align="justify"> En este repositorio, encontrarás todos los archivos y guías educativas necesarias para entender con totalidad e incluso tomarte la libertad creativa de mejorar este proyecto. Las carpetas y archivos han sido llamados con nombres que se explican a ellos mismos para hacer la navegación más intuitiva. </p>

___

### <p align="justify"> Características principales [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

- <p align="justify"> Desarrollado usando la HelTec CubeCell HTCC-AB01 (Una placa de muy bajo consumo con LoRa implementado y que soporta recarga con panel solar y gestión de batería) </p>

  <div align="center">
    <img src="https://alexcorvis.cc/content/images/2020/10/cubecell_htcc-ab01_pinout.png" width="600"  style="margin: 10px;"/>
  </div>
  <br/>

- <p align="justify"> Cambios realizados para añadirle, además, un sensor CCS811 (Sensor de partículas volátiles) </p>

  <div align="center">
    <img src="https://www.az-delivery.de/cdn/shop/products/kohlendioxid-gassensor-metalloxid-ccs811-sensor-mit-hochempfindlichem-on-board-detektionssensormodul-fur-die-luftqualitat-432838.jpg?v=1679398782&width=1200" width="600"  style="margin: 10px;"/>
  </div>
  <br/>

<div align="justify">

- <p align="justify"> Carcasa a medida para encapsular todos los componentes a un tamaño similar al de la batería del drone (Envase + Recipiente) </p>

  <div align="center">
    <img src="https://github.com/medialablpwan/droneloraminiairqualitystation/blob/main/pics/Screenshot%202023-12-09%20150934.png" width="600"  style="margin: 10px;"/>
  </div>
  <br/>
  <div align="center">
    <img src="https://github.com/medialablpwan/droneloraminiairqualitystation/blob/main/pics/Screenshot%202023-12-09%20151020.png" width="600"  style="margin: 10px;"/>
  </div>
  <br/>

  > Ejemplo de ensamblaje:
  <div align="center">
    <img src="https://github.com/medialablpwan/droneloraminiairqualitystation/blob/main/pics/photo_5974565629660871395_y.jpg" width="600"  style="margin: 10px;"/>
  </div>
  <br/>

> [!WARNING]
> Hacen falta seis tornillos M3 para fijar el ensamblado y dos bridas para ajustarlo al frame del drone

___

### <p align="justify"> Lista de componentes [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

<div align="center">

| Componente | Modelo |
| ------------- | ------------- |
| Placa  | [CubeCell HTCC-AB01](https://es.aliexpress.com/item/1005005164213870.html?spm=a2g0o.productlist.main.5.15a56dbeZ61KNC&algo_pvid=e097d9ae-f862-4bfa-968b-de8f8e1df81d&algo_exp_id=e097d9ae-f862-4bfa-968b-de8f8e1df81d-2&pdp_npi=4%40dis%21EUR%2118.31%2116.66%21%21%2119.30%21%21%40211b600d17021349784998863e33dc%2112000031936098658%21sea%21ES%210%21AB&curPageLogUid=9XVYaSeuxzMV) |
| Sensor atmosférico  | [BME280](https://www.tinytronics.nl/shop/en/sensors/distance/waterproof-ultrasonic-sensor-jsn-sr04t) |
| Sensor de partículas volátiles  | [CCS811](https://www.tinytronics.nl/shop/en/power/batteries/18650/eve-18650-li-ion-battery-3100mah-10a-inr18650-33v) |
| Batería | [LiPo 1S 3700mAh](https://www.tinytronics.nl/shop/en/power/solar-energy/solar-panels/solar-panel-with-dc-dc-converter-and-usb-5v-1a) |
| Carcasa  | [A medida (archivo inlcuido)](https://github.com/medialablpwan/lorawaterlevelmonitoring/tree/main/carc) |

</div>

___

### <p align="justify"> Lista de conexiones [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

<div align="center">

| BME280 | CCS811 | LiPo | CubeCell |
| ------------- | ------------- | ------------- | ------------- |
| `SDA` | `SDA` | - | `SDA` |
| `SCL` | `SCL` | - | `SCL` |
| `Vin` | `Vin` | - | `Vext` |
| `GND` | `GND` | - | `GND` |
| - | - | `Con Bat` | `Con Bat` |

</div>

> En una protoboard se ve de la siguienta forma:

<div align="center">
  <img src="https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/pics/1_ensayo.jpg" width="600"  style="margin: 10px;"/>
</div>
<br/>

___

### <p align="justify"> Flujograma (¡Simplificado!) [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

```mermaid
graph TD;
  A[Encender] -->|1| B(Despertarse si se está en deep sleep)
  B -->|2| C(Obtener las medidas de la batería y de los sensores BME y CCS)
  C -->|3| D(Mandar los bytes a TTN)
  D -->|4| E(Temporizar la tasa de transmisión de datos)
  E -->|5| F(Ir a deep sleep)
  F -->|6| B
```

___

<div align="justify">

### Archivos de código [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice)

En esta sección, se da una descripción breve a cómo está distribuido el código entre los archivos en [`medialablpwan/lorawaterlevelmonitoring/main/`](https://github.com/medialablpwan/lorawaterlevelmonitoring/tree/main/main), donde el código está disponible para flashear o editar:

- [`main.cpp`](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/main/main.ino)
  ```C
  /*
  Algoritmo completo
  */
  ```
- [`ttnvalues.h`](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/main/sensor.ino)
  ```C
  /*
  Claves OTAA para sincronizarse en TTN
  */
  ```

Un análisis más en profundidad viene dado en el propio código ya que cada función está explicada con comentarios.

</div>

> [!TIP]
> Los archivos más importantes a editar son `sensor.ino`, donde se puede implementar cualquier sensor, y `configuration.h`, donde se declaran las macros de los periféricos

> [!CAUTION]
> Se necesita código adicional para implementar I/O por I2C. Las funciones para hacerlo funcionar están en el proyecto original en [`TTGO-PAXCOUNTER-LoRa32-V2.1-TTN/main/main.ino`](https://github.com/rwanrooy/TTGO-PAXCOUNTER-LoRa32-V2.1-TTN/blob/master/main/main.ino)

___

___

## <p align="justify"> Experimento de despliegue [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

### <p align="justify"> La primera unidad se ha desplegado cerca de la Escuela Politécnica de Ingeniería de Gijón: </p>

<div align="center">
  <img src="https://github.com/medialablpwan/waterlevelcontrol/blob/main/pics/9_Sensor%20Cooper%20en%20Arroyo%20de%20San%20Miguel.jpg" width="600"  style="margin: 10px;"/>
</div>
<br/>
<div align="center">
  <img src="https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/pics/map.png" width="600"  style="margin: 10px;"/>
</div>
<br/>

___

### Accede al panel de Grafana[^1] por medio de este código QR o el link de debajo:

<div align="center">
  <img src="https://github.com/medialablpwan/waterlevelcontrol/blob/main/pics/qrcode_4f566df1fed52c6e7fd5f661f64ae3eb.balena-devices.com.png" width="600"  style="margin: 10px;"/>
</div>
<br/>

<p align="center"> http://4f566df1fed52c6e7fd5f661f64ae3eb.balena-devices.com:8080/d/vJhQNCZgz/sensores-jsn-sr04t-arroyo-de-san-miguel?from=now-24h&orgId=1&to=now&refresh=1m </p>

___

___

## <p align="justify"> Licencia [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

Este proyecto está licenciado bajo la [GPL-3.0 license](https://github.com/rwanrooy/TTGO-PAXCOUNTER-LoRa32-V2.1-TTN/blob/master/LICENSE). Contiene código de [rwanrooy/TTGO-PAXCOUNTER-LoRa32-V2.1-TTN](https://github.com/rwanrooy/TTGO-PAXCOUNTER-LoRa32-V2.1-TTN)

___

### <p align="justify"> Contacto [:leftwards_arrow_with_hook:](https://github.com/medialablpwan/lorawaterlevelmonitoring/blob/main/README_ES.md#%C3%ADndice) </p>

> [!IMPORTANT]
> Responderemos amablemente a dudas y leeremos sugerencias: [![Gmail Badge](https://img.shields.io/badge/-Gmail-c14438?style=for-the-badge&logo=Gmail&logoColor=white&link=mailto:medialablpwan@gmail.com)](mailto:medialablpwan@gmail.com)
> 
> Más información sobre nuestras actividades: [![Linkedin Badge](https://img.shields.io/badge/-LinkedIn-blue?style=for-the-badge&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/groups/9298597/)](https://www.linkedin.com/groups/9298597/)

_<p align="justify"> Autores: Daniel Rodríguez Moya, Iván Graña y el grupo de trabajo de MediaLab\_ LPWAN :shipit: </p>_

[^1]: Instrucciones sobre como desplegar paneles de Grafana en el siguiente repo [`medialablpwan/documentacion`](https://github.com/medialablpwan/documentacion).
