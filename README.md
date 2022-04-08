# nrf52_lvgl_porting

- SDK : nRF5_SDK_15.2.0_9412b96
- IDE : Keil
- LVGL : v8.2
- project : nRF5_SDK_15.2.0_9412b96\examples\peripheral\ili9341_lvgl_test
- monitor : 2.4 吋 TFT+觸控螢幕 ILI9341 SPI液晶屏模塊 240*320 (ili9341.c ili9341.h為驅動，參考 nRF5_SDK_15.2.0_9412b96\components\drivers_ext\ili9341 )
![image](https://user-images.githubusercontent.com/44420087/162472861-55d3612a-1763-4a74-acbe-10ca247e2c36.png)

- (P.S.) 此Project 有用到nrf_lcd.h，路徑在(nRF5_SDK_15.2.0_9412b96\components\libraries\gfx)

### Project Folder diagram
```mermaid
graph TD;
     lvgl
     subgraph Folder
     lvgl_app
     lvgl_driver
     lvgl_port
     end
     lvgl --> |應用層|lvgl_app
     lvgl --> |驅動層|lvgl_driver
     lvgl --> |移植層|lvgl_port
     lvgl --> lv_conf.h
     lvgl --> lvgl.h
```

## LVGL 移植

https://hackmd.io/kboEbfFgSI29kvuhmhYtrQ

## 成果
![](https://i.imgur.com/0sl662R.jpg)
