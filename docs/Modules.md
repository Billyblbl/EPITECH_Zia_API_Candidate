# Modules

ZIAAPI defines two types of modules :
- [Active Layers](#active-layers)
- [Filter Overlays](#filter-overlays)

Layers must implement the `ILayer` interface, while Overlays must implement the `IOverlay` interface.

## Library symbols

To be loadable by a ZIAAPI compatible core, Layer & Overlay modules must define C-style functions with signature equivalent to:
```c++
ILayer	*CreateLayer();
void	*DestroyLayer(ILayer *);
```
for Layer modules and:
```c++
IOverlay	*CreateOverlay();
void		*DestroyOverlay(IOverlay *);
```
for Overlay modules.
The `Create*` functions each allocate the necessary memory and construct an implementation of their respective interfaces as-if `new` constructed.
The `Destroy*`functions each destroy and dealocates the memory occupied by an implementation of their respective interfaces, built by their respective `Create*` functions, as-if destroyed by call to `delete`
To ensure symbol preservation against `c++` symbol mangling the definition of these factory function should be placed in an `extern "C"` clause such as
```c++
extern "C" {

	IOverlay	*CreateOverlay();
	{
		return new OverlayImplementation;
	}

	void		*DestroyOverlay(IOverlay *overlay)
	{
		delete overlay;
	}

}
```
_Note that these definition are exemples of the simplest way to define them_

## Active Layers

An active layer must be a complete implementation in a module of the `ILayer` interface, using the virtual call `onRequest` as its main implementation point.

## Filter Overlays

A filter overlay must be a complete implementation in a module of the `IOverlay` interface, using the virtual calls `onRequest` and `onResponse` as its main implementation points.
