#include "MGGameplayTags.h"

namespace MGGameplayTags
{
	// 캐릭터의 기본 움직임
	UE_DEFINE_GAMEPLAY_TAG(MG_Input_Move, "MG.Input.Move");
	UE_DEFINE_GAMEPLAY_TAG(MG_Input_Look, "MG.Input.Look");
	UE_DEFINE_GAMEPLAY_TAG(MG_Input_Jump, "MG.Input.Jump");
	
	// 캐릭터의 능력
	UE_DEFINE_GAMEPLAY_TAG(MG_Input_Fire, "MG.Input.Fire");
}