// <copyright file="main.cpp" company="Zodiac Aerospace">
// Copyright (c) 2020 - All rights reserved.
// </copyright>
// <author>Peter.Evans</author>
// <date>7/27/2020</date>
// <summary>Implements the main C-Hook entry point functions</summary>

// Mastercam 2020 C-Hook Add-In

#include "stdafx.h"
#include "resource.h"
#include "SetCoolantParameters.h"  // GetCHookResourceHandle()
// *** Imported "directly" from Mastercam ***
__declspec (dllimport) bool CoolantIsInCannedText(short *cannedText);
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/// <summary> The REQUIRED m_version function. </summary>
///
/// <remarks> Mastercam calls this function first, when your C-Hook is about to be run.
///           It passes in a Version# that represents the current version of Mastercam
///           that is about to attempt to run the C-Hook.
///           This allows you to check if your C-Hook can run on this version of Mastercam.
///           If so, just return (to Mastercam) the same version number that was supplied,
///           else some other value to abort the running of the C-Hook.
///           </remarks>
///
/// <param name="version"> The version (supplied by Mastercam). </param>
///
/// <returns> The supplied version if OK to run, else any other value to abort. </returns>
extern "C" __declspec(dllexport) int m_version (int version)
	{
	int ret = C_H_VERSION;

	// Allow this C-Hook to run in any version of Mastercam
	// that has the same major version.
	if ( (version / 100) == (C_H_VERSION / 100) )
		ret = version;

	return ret;
	}

/// <summary> The entry point function referenced in an associated Function Table (FT) file. </summary>
///
/// <remarks> If a C-Hook Add-In has an associated Function Table (FT) file,
///           you can specific one (or more) entry points into the Add-In.
///           The FT file also allows (requires) you to specify (2) icon images and a string
///           tooltip description for the Add-In. These resources will appear in Mastercam's
///           Settings-Customize allowing a user to add the C-Hook's icon to a toolbar in Mastercam.
///           This function's name must appear in a FUNCTION CPP line in the FT file in order to get called.
///           </remarks>
///
/// <param name="optional"> An optional integer value passed via a 'PARAM #' statement in the FT file. 
///                         (Default value is always 0)</param>
///
/// <returns> The MC_RETURN state flag(s) back to Mastercam. </returns>
extern "C" __declspec(dllexport) int SetFloodBeforeEntry(int optional)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	for (auto index = 0; index < TpMainOpMgr.GetMainOpList().GetSize(); ++index)
	{
		auto op = TpMainOpMgr.GetMainOpList()[index];
		if (op->cantxt.cantxt[0] == -4101 || op->cantxt.cantxt[0] == -5101)
		{
			op->cantxt.cantxt[0] = -3101;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
	}

#ifdef _DEBUG
		return MC_NOERROR | MC_UNLOADAPP;
#else
		return MC_NOERROR;
#endif
	
}
extern "C" __declspec(dllexport) int SetFloodWithEntry(int optional)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	for (auto index = 0; index < TpMainOpMgr.GetMainOpList().GetSize(); ++index)
	{
		auto op = TpMainOpMgr.GetMainOpList()[index];
		if (op->cantxt.cantxt[0] == -3101)
		{
			op->cantxt.cantxt[0] = -4101;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[1] == -3103)
		{
			op->cantxt.cantxt[1] = -4103;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[2] == -3105)
		{
			op->cantxt.cantxt[2] = -4105;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[0] == -3102)
		{
			op->cantxt.cantxt[0] = -4102;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
	}
		if (op->cantxt.cantxt[1] == -3104)
		{
			op->cantxt.cantxt[1] = -4104;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[2] == -3106)
		{
			op->cantxt.cantxt[2] = -4106;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
	}
#ifdef _DEBUG
		return MC_NOERROR | MC_UNLOADAPP;
#else
		return MC_NOERROR;
#endif
	
}
extern "C" __declspec(dllexport) int SetFloodAfterEntry(int optional)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	for (auto index = 0; index < TpMainOpMgr.GetMainOpList().GetSize(); ++index)
	{
		auto op = TpMainOpMgr.GetMainOpList()[index];
		if (op->cantxt.cantxt[0] == -3101)
		{
			op->cantxt.cantxt[0] = -5101;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[1] == -3103)
		{
			op->cantxt.cantxt[1] = -5103;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
    	}
		if (op->cantxt.cantxt[2] == -3105)
		{
			op->cantxt.cantxt[2] = -5105;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[0] == -3102)
		{
			op->cantxt.cantxt[0] = -5102;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[1] == -3104)
		{
			op->cantxt.cantxt[1] = -5104;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
		if (op->cantxt.cantxt[2] == -3106)
		{
			op->cantxt.cantxt[2] = -5106;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
	}

#ifdef _DEBUG
		return MC_NOERROR | MC_UNLOADAPP;
#else
		return MC_NOERROR;
#endif
	
}

extern "C" __declspec(dllexport) int LiftHoodSel(int optional)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	for (auto index = 0; index < TpMainOpMgr.GetMainOpList().GetSize(); ++index)
	{
		auto op = TpMainOpMgr.GetMainOpList()[index];
		if (op->db.select_flag)
		{
				op->cantxt.cantxt[3] = -4107;
				bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
				operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
	}

#ifdef _DEBUG
	return MC_NOERROR | MC_UNLOADAPP;
#else
	return MC_NOERROR;
#endif

}

extern "C" __declspec(dllexport) int LiftHoodAll(int optional)
{
	// Must call this prior to accessing any Resources in the C-Hook DLL !
	ChangeResCl res(GetChookResourceHandle());
	for (auto index = 0; index < TpMainOpMgr.GetMainOpList().GetSize(); ++index)
	{
		auto op = TpMainOpMgr.GetMainOpList()[index];
		if (op->db.select_flag)
		{
			op->cantxt.cantxt[3] = -4107;
			bool succf{}; DB_LIST_ENT_PTR ptr = nullptr;
			operation_manager(op, OPMGR_REWRITE, &ptr, &succf);
		}
	}

#ifdef _DEBUG
	return MC_NOERROR | MC_UNLOADAPP;
#else
	return MC_NOERROR;
#endif
}

/// <summary> The REQUIRED m_main entry point function. </summary>
///
/// <remarks> This is the main entry point function of the C-Hook Add-In.
///           It is called by Mastercam to start the C-Hook, when...
///           The C-Hook is started via the Main Menu: Setting-Run User Application.
///           - or -
///           The C-Hook has an associated Function Table (FT) file that references
///           m_main in the FUNCTION CPP line.
///           </remarks>
/// <param name="param"> An optional value supplied via a PARAM command in the FT file. </param>
///
/// <returns> The MC_RETURN state flag(s) back to Mastercam. </returns>
extern "C" __declspec(dllexport) int m_main (int param)
	{
	return 0;
	}
