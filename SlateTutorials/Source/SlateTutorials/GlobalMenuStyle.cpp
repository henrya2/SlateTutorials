#include "SlateTutorials.h"
#include "GlobalMenuStyle.h"

void FGlobalStyle::GetResources(TArray<const FSlateBrush*> & OutBrushes) const
{

}

const FName FGlobalStyle::TypeName = TEXT("FGlobalStyle");

const FName FGlobalStyle::GetTypeName() const
{
	return TypeName;
}

const FGlobalStyle& FGlobalStyle::GetDefault()
{
	static FGlobalStyle Default;
	return Default;
}
