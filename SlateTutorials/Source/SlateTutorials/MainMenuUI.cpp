#include "SlateTutorials.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "MenuStyles.h"
#include "GlobalMenuStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuUI::Construct(const FArguments& InArgs)
{
	MainMenuHUD = InArgs._MainMenuHUD;
	MenuStyle = &FMenuStyles::Get()->GetWidgetStyle<FGlobalStyle>(TEXT("Global"));

	ChildSlot
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.TextStyle(&MenuStyle->MenuTitleStyle)
				.Text(FText::FromString(TEXT("Main Menu")))
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
					SNew(SButton)
					.ButtonStyle(&MenuStyle->MenuButtonStyle)
					.TextStyle(&MenuStyle->MenuButtonTextStyle)
					.Text(FText::FromString(TEXT("Play Game!")))
					.OnClicked(this, &SMainMenuUI::PlayGameClicked)
				]
				+SVerticalBox::Slot()
				[
					SNew(SButton)
					.ButtonStyle(&MenuStyle->MenuButtonStyle)
					.TextStyle(&MenuStyle->MenuButtonTextStyle)
					.Text(FText::FromString(TEXT("Quit Game!")))
					.OnClicked(this, &SMainMenuUI::QuitGameClicked)
				]
			]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuUI::PlayGameClicked()
{
	if (MainMenuHUD.IsValid())
	{
		MainMenuHUD->PlayGameClicked();
	}
	return FReply::Handled();
}

FReply SMainMenuUI::QuitGameClicked()
{
	if (MainMenuHUD.IsValid())
	{
		MainMenuHUD->QuitGameClicked();
	}
	return FReply::Handled();
}
