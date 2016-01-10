#include "SlateTutorials.h"
#include "MenuStyles.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FMenuStyles::MenuStyleInstance = nullptr;

void FMenuStyles::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FMenuStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

TSharedPtr<class ISlateStyle> FMenuStyles::Get()
{
	return MenuStyleInstance;
}

FName FMenuStyles::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyles"));
	return StyleSetName;
}

TSharedRef<class FSlateStyleSet> FMenuStyles::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMenuStyles::GetStyleSetName(), TEXT("/Game/UI/Styles"), TEXT("/Game/UI/Styles"));
	return StyleRef;
}
