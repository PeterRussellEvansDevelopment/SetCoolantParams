// <copyright file="SetCoolantParameters.h" company="Zodiac Aerospace">
// Copyright (c) 2020 - All rights reserved.
// </copyright>
// <author>Peter.Evans</author>
// <date>7/27/2020</date>
// <summary> Declarations for the SetCoolantParameters C-Hook AddOn. </summary>
 
#pragma once

/// <summary> Retrieves the handle to the resources for this C-Hook DLL </summary>
/// 
///<remarks>  You MUST call -> ChangeResCl res (GetChookResourceHandle());
///           PRIOR to accessing any "resources" in your C-Hook! </remarks>
/// 
/// <returns> The C-Hook's resource handle. </returns>
HINSTANCE GetChookResourceHandle ();
