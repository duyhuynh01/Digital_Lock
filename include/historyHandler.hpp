#include <FS.h>
#include <SPIFFS.h>
#include <CircularBuffer.h>
#define HISTORY_LENGTH 20

using namespace fs;

class HistoryHandler
{
    CircularBuffer<String, HISTORY_LENGTH> historyBuffer;

public:
    HistoryHandler();
    ~HistoryHandler();
    void loadHistory(); // load history from flash memory into a local buffer
    void logHistory(const String &entry);
    void saveHistoryToFile();
    void clearFileInMemory();
    void updateHistory(const String &entry);
    void showHistory();
};