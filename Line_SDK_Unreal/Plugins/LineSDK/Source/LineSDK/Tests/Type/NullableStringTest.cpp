#include "Misc/AutomationTest.h"
#include "Type/NullableString.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(NullableStringTest, "Tests.Type.NullableStringTest",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

/**
 * Make the test pass by returning true,
 * or fail by returning false.
 */
bool NullableStringTest::RunTest(const FString& Parameters)
{
	auto What = TEXT("");

	FNullableString String;
	if (!TestTrue(TEXT("Default is Null"), String.IsNull())) return false;

	String = FString("Hello, ") + "World!";
	if (!TestFalse(What, String.IsNull())) return false;
	if (!TestEqual(What, String.GetValue(), TEXT("Hello, World!"))) return false;

	String = FNullableString();
	if (!TestTrue(What, String.IsNull())) return false;

	String = FNullableString(TEXT("123456ABCDEF"));
	if (!TestFalse(What, String.IsNull())) return false;
	if (!TestEqual(What, String.GetValue(), TEXT("123456ABCDEF"))) return false;

	return true;
}
