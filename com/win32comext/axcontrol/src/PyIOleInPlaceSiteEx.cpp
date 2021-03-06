// This file implements the IOleInPlaceSiteEx Interface and Gateway for Python.
// Generated by makegw.py

#include "axcontrol_pch.h"
#include "PyIOleWindow.h"
#include "PyIOleInPlaceSite.h"
#include "PyIOleInPlaceSiteEx.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIOleInPlaceSiteEx::PyIOleInPlaceSiteEx(IUnknown *pdisp):
	PyIOleInPlaceSite(pdisp)
{
	ob_type = &type;
}

PyIOleInPlaceSiteEx::~PyIOleInPlaceSiteEx()
{
}

/* static */ IOleInPlaceSiteEx *PyIOleInPlaceSiteEx::GetI(PyObject *self)
{
	return (IOleInPlaceSiteEx *)PyIOleInPlaceSite::GetI(self);
}

// @pymethod |PyIOleInPlaceSiteEx|OnInPlaceActivateEx|Description of OnInPlaceActivateEx.
PyObject *PyIOleInPlaceSiteEx::OnInPlaceActivateEx(PyObject *self, PyObject *args)
{
	IOleInPlaceSiteEx *pIOIPSE = GetI(self);
	if ( pIOIPSE == NULL )
		return NULL;
	// @pyparm int|dwFlags||Description for dwFlags
	BOOL pfNoRedraw;
	DWORD dwFlags;
	if ( !PyArg_ParseTuple(args, "i:OnInPlaceActivateEx", &dwFlags) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOIPSE->OnInPlaceActivateEx( &pfNoRedraw, dwFlags );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);

	PyObject *pyretval = Py_BuildValue("i", pfNoRedraw);
	return pyretval;
}

// @pymethod |PyIOleInPlaceSiteEx|OnInPlaceDeactivateEx|Description of OnInPlaceDeactivateEx.
PyObject *PyIOleInPlaceSiteEx::OnInPlaceDeactivateEx(PyObject *self, PyObject *args)
{
	IOleInPlaceSiteEx *pIOIPSE = GetI(self);
	if ( pIOIPSE == NULL )
		return NULL;
	// @pyparm int|fNoRedraw||Description for fNoRedraw
	BOOL fNoRedraw;
	if ( !PyArg_ParseTuple(args, "i:OnInPlaceDeactivateEx", &fNoRedraw) )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOIPSE->OnInPlaceDeactivateEx( fNoRedraw );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod |PyIOleInPlaceSiteEx|RequestUIActivate|Description of RequestUIActivate.
PyObject *PyIOleInPlaceSiteEx::RequestUIActivate(PyObject *self, PyObject *args)
{
	IOleInPlaceSiteEx *pIOIPSE = GetI(self);
	if ( pIOIPSE == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":RequestUIActivate") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIOIPSE->RequestUIActivate( );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return OleSetOleError(hr);
	Py_INCREF(Py_None);
	return Py_None;

}

// @object PyIOleInPlaceSiteEx|Description of the interface
static struct PyMethodDef PyIOleInPlaceSiteEx_methods[] =
{
	{ "OnInPlaceActivateEx", PyIOleInPlaceSiteEx::OnInPlaceActivateEx, 1 }, // @pymeth OnInPlaceActivateEx|Description of OnInPlaceActivateEx
	{ "OnInPlaceDeactivateEx", PyIOleInPlaceSiteEx::OnInPlaceDeactivateEx, 1 }, // @pymeth OnInPlaceDeactivateEx|Description of OnInPlaceDeactivateEx
	{ "RequestUIActivate", PyIOleInPlaceSiteEx::RequestUIActivate, 1 }, // @pymeth RequestUIActivate|Description of RequestUIActivate
	{ NULL }
};

PyComTypeObject PyIOleInPlaceSiteEx::type("PyIOleInPlaceSiteEx",
		&PyIOleInPlaceSite::type,
		sizeof(PyIOleInPlaceSiteEx),
		PyIOleInPlaceSiteEx_methods,
		GET_PYCOM_CTOR(PyIOleInPlaceSiteEx));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGOleInPlaceSiteEx::OnInPlaceActivateEx(
		/* [out] */ BOOL __RPC_FAR * pfNoRedraw,
		/* [in] */ DWORD dwFlags)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	HRESULT hr=InvokeViaPolicy("OnInPlaceActivateEx", &result, "i", dwFlags);
	if (FAILED(hr)) return hr;
	// Process the Python results, and convert back to the real params
	if (!PyArg_Parse(result, "i" , pfNoRedraw)) return PyCom_HandlePythonFailureToCOM(/*pexcepinfo*/);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGOleInPlaceSiteEx::OnInPlaceDeactivateEx(
		/* [in] */ BOOL fNoRedraw)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("OnInPlaceDeactivateEx", NULL, "i", fNoRedraw);
	return hr;
}

STDMETHODIMP PyGOleInPlaceSiteEx::RequestUIActivate(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("RequestUIActivate", NULL);
	return hr;
}

