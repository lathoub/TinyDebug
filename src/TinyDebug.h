
#ifdef SerialMon
#define DEBUG_PRINT(...) SerialMon.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...) SerialMon.println(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif
/*
void debug_setup()
{
  // Set console baud rate
#ifdef SerialMon
  SerialMon.begin(115200);
  while (!SerialMon) {}
  SerialMon.println(F("\nBooting..."));
#endif
}
*/
/*
#ifdef SerialMon
namespace {
template <typename T>
static void DBG_PLAIN(T last) {
  SerialMon.println(last);
}

template <typename T, typename... Args>
static void DBG_PLAIN(T head, Args... tail) {
  SerialMon.print(head);
  SerialMon.print(' ');
  DBG_PLAIN(tail...);
}

template <typename... Args>
static void DBG(Args... args) {
  SerialMon.print(GF("["));
  SerialMon.print(millis());
  SerialMon.print(GF("] "));
  DBG_PLAIN(args...);
}
}  // namespace
#else
#define DBG_PLAIN(...)
#define DBG(...)
#endif
*/