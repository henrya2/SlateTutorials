// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateTutorials.h"
#include "MenuStyles.h"


// Custom implementation of the Default Game Module.
class FSlateTutorialsGameModule : public FDefaultGameModuleImpl
{
	// Called whenever the module is starting up. In here, we unregister any style sets 
	// (which may have been added by other modules) sharing our 
	// style set's name, then initialize our style set. 
	virtual void StartupModule() override
	{
		//Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FMenuStyles::GetStyleSetName());
		FMenuStyles::Initialize();
	}

	// Called whenever the module is shutting down. Here, we simply tell our MenuStyles to shut down.
	virtual void ShutdownModule() override
	{
		FMenuStyles::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FSlateTutorialsGameModule, SlateTutorials, "SlateTutorials");
