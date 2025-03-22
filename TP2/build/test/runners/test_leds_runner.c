/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
/* injected defines for unity settings, etc */
#ifndef UNITY_EXCLUDE_FLOAT
#define UNITY_EXCLUDE_FLOAT
#endif /* UNITY_EXCLUDE_FLOAT */
#include "leds.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_todos_los_leds_inician_apagados(void);
extern void test_prender_led_individual(void);
extern void test_apagar_led_individual(void);
extern void test_prender_y_apagar_algunos_leds(void);
extern void test_prender_todos_los_leds_de_una_vez(void);
extern void test_apagar_todos_los_leds_de_una_vez(void);
extern void test_consultar_el_estado_de_un_led_encendido(void);

/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Teardown (stub)=====*/
void tearDown(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
  Unity.CurrentTestName = name;
  Unity.CurrentTestLineNumber = (UNITY_UINT)line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
  if(!UnityTestMatches())
    return;
#endif
  Unity.NumberOfTests++;
  UNITY_CLR_DETAILS();
  UNITY_EXEC_TIME_START();
  CMock_Init();
  if(TEST_PROTECT())
  {
    setUp();
    func();
  }
  if(TEST_PROTECT())
  {
    tearDown();
    CMock_Verify();
  }
  CMock_Destroy();
  UNITY_EXEC_TIME_STOP();
  UnityConcludeTest();
}

/*=======MAIN=====*/
int main(int argc, char** argv)
{
#ifdef UNITY_USE_COMMAND_LINE_ARGS
  int parse_status = UnityParseOptions(argc, argv);
  if(parse_status != 0)
  {
    if(parse_status < 0)
    {
      UnityPrint("test_leds.");
      UNITY_PRINT_EOL();
      UnityPrint("  test_todos_los_leds_inician_apagados");
      UNITY_PRINT_EOL();
      UnityPrint("  test_prender_led_individual");
      UNITY_PRINT_EOL();
      UnityPrint("  test_apagar_led_individual");
      UNITY_PRINT_EOL();
      UnityPrint("  test_prender_y_apagar_algunos_leds");
      UNITY_PRINT_EOL();
      UnityPrint("  test_prender_todos_los_leds_de_una_vez");
      UNITY_PRINT_EOL();
      UnityPrint("  test_apagar_todos_los_leds_de_una_vez");
      UNITY_PRINT_EOL();
      UnityPrint("  test_consultar_el_estado_de_un_led_encendido");
      UNITY_PRINT_EOL();
      return 0;
    }
    return parse_status;
  }
#endif
  UnityBegin("test_leds.c");
  run_test(test_todos_los_leds_inician_apagados, "test_todos_los_leds_inician_apagados", 54);
  run_test(test_prender_led_individual, "test_prender_led_individual", 63);
  run_test(test_apagar_led_individual, "test_apagar_led_individual", 70);
  run_test(test_prender_y_apagar_algunos_leds, "test_prender_y_apagar_algunos_leds", 78);
  run_test(test_prender_todos_los_leds_de_una_vez, "test_prender_todos_los_leds_de_una_vez", 88);
  run_test(test_apagar_todos_los_leds_de_una_vez, "test_apagar_todos_los_leds_de_una_vez", 95);
  run_test(test_consultar_el_estado_de_un_led_encendido,
           "test_consultar_el_estado_de_un_led_encendido", 103);

  return UNITY_END();
}
