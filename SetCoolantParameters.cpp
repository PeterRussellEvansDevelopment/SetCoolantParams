// <copyright file="SetCoolantParameters.cpp" company="Zodiac Aerospace">
// Copyright (c)2020 - All rights reserved.
// </copyright>
// <author>Peter.Evans</author>
// <date>7/27/2020</date>
// <summary>Implements the DllMain for the C-Hook (MFC extension) DLL</summary>

#include "stdafx.h"
#include <afxdllx.h>

/// <summary> Handle to the Resources of the C-Hook. </summary>
HINSTANCE resHandle = nullptr;

/// <summary> Retrieves the Handle to the Resources for this DLL. </summary>
///
/// <returns> This C-Hook's resource handle. </returns>
HINSTANCE GetChookResourceHandle ()
	{
	return resHandle;
	}

static AFX_EXTENSION_MODULE SetCoolantParametersDLL = { NULL, NULL };

extern "C" int APIENTRY DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
	{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER (lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
		{
		TRACE (_T ("SetCoolantParameters.DLL Initializing!\n"));

		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule (SetCoolantParametersDLL, hInstance))
			return 0;

		// Saves the DLL instance handle for later use with ChangeResCl. 
		resHandle = hInstance;
		
		// If you use a separate resource DLL, you should load it here using AfxLoadLibrary 
		// and save that handle here and in the extension module structure.
		// resHandle = AfxLoadLibrary(_T ("Resources\\SetCoolantParametersRes.dll"));
		
		if (resHandle == nullptr)
			return 0;

		// Save the handle of the resources in the extension module structure.
		SetCoolantParametersDLL.hResource = resHandle;
		}
	else if (dwReason == DLL_PROCESS_DETACH)
		{
		TRACE (_T ("SetCoolantParameters.DLL Terminating!\n"));
		
		// This is required because C-Hooks are explicitly loaded by Mastercam.
		if (resHandle)
			AfxFreeLibrary (resHandle);

		// Terminate the library before destructors are called
		AfxTermExtensionModule (SetCoolantParametersDLL);
		}

	return 1; // ok
	}
