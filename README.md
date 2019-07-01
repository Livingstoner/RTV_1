# RTV_1
Basic Ray Tracer

## Algorithm overview
*Optical ray tracing describes a method for producing visual images constructed in 3D computer graphics environments, with more photorealism than either ray casting or scanline rendering techniques. It works by tracing a path from an imaginary eye through each pixel in a virtual screen, and calculating the color of the object visible through it.*

## Scene file
*In `scenes` directory you can find files which consists description of objects which will be added to the RT scene.
You could easily modify file by adding objects setting their `color`, `position`, `direction` and `radius` in the brackets `{}`.
It looks like :*
```
Sphere
{
    pos(0.0, 0.0, 0.0)
    color(255, 255, 0)
    rad = 1
}
```

## Light
*To our object we need to add a `light` to see object, in our way it is a sphere.
So you shoud add in parser to our sphere light block. It has 2 variables : `position` and `intense`.
By changing 'intense' you could increase/decrease how intensive our light will shine to out objects.*
```
Light
{
	pos(5.0, 5.0, -5.0)
	intense 1
}
```
## Camera
*So we have 'light' and an object sphere in our scene. But according to `Algorith overwiew` to see how our scene is rendering we need to add `camera`. It has 2 variables : `position` and `to`.
`to` specifies in which coordinate our camera will watch :*
```
Camera
{
	pos(0.0, 0.0, -10.0)
	to(0.0, 0.0, 0.0)
}
```

## To run it you need to
```
1) git clone https://github.com/Livingstoner/RTV_1.git
2) make
3) ./rtv scenes/(scene_file)
```
<img width="1241" alt="Screen Shot 2019-07-01 at 4 15 53 AM" src="https://user-images.githubusercontent.com/40596629/60405335-14fe2b00-9bb8-11e9-816d-106e02107ea4.png">
*In my project you could see this scene in `scenes/sphere`*

## Objects
- *Plane*
- *Sphere*
- *Cone*
- *Cylinder*

## Scenes
<img width="1240" alt="Screen Shot 2019-07-01 at 4 22 17 AM" src="https://user-images.githubusercontent.com/40596629/60405282-dc5e5180-9bb7-11e9-9a93-cae958f78283.png">
<img width="1241" alt="Screen Shot 2019-07-01 at 4 23 25 AM" src="https://user-images.githubusercontent.com/40596629/60405345-27786480-9bb8-11e9-8164-6a9a7dbb4f90.png">
<img width="1239" alt="Screen Shot 2019-07-01 at 4 25 59 AM" src="https://user-images.githubusercontent.com/40596629/60405367-5abaf380-9bb8-11e9-91ae-6cfcf1e5d4b8.png">
<img width="1242" alt="Screen Shot 2019-07-01 at 4 27 36 AM" src="https://user-images.githubusercontent.com/40596629/60405399-92c23680-9bb8-11e9-952f-98f8994ae1f0.png">
<img width="1241" alt="Screen Shot 2019-07-01 at 4 28 13 AM" src="https://user-images.githubusercontent.com/40596629/60405429-c56c2f00-9bb8-11e9-9ee2-8de70f7cf3a0.png">
<img width="1241" alt="Screen Shot 2019-07-01 at 4 29 46 AM" src="https://user-images.githubusercontent.com/40596629/60405441-e16fd080-9bb8-11e9-9c92-6d7ccdef8695.png">
