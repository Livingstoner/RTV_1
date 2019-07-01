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
*In my project you could see this scene in `scenes/sphere`*

## Objects
- *Plane*
- *Sphere*
- *Cone*
- *Cylinder*

## Scenes
