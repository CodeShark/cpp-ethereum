EXE_EXT = .exe

CXX = x86_64-w64-mingw32-g++

CXX_FLAGS = -Wall -std=c++11

INCLUDE_PATH += \
    -I./ \
    -I/usr/x86_64-w64-ming32/include \
    -I../libethereum \
    -I../../cryptopp562 \
    -I../../secp256k1/include

LIB_PATH += \
    -L/usr/x86_64-w64-mingw32/lib \
    -L../libethereum/lib \
    -L../../cryptopp562 \
    -L../../secp256k1

LIBS += \
    -static-libgcc \
    -static-libstdc++ \
    -static \
    -lgcc \
    -lgdi32 \
    -lethereum \
    -lcryptopp \
    -lgmp \
    -lleveldb \
    -lminiupnpc \
    -liphlpapi \
    -lboost_system-mt-s \
    -lboost_filesystem-mt-s \
    -lboost_chrono-mt-s \
    -lboost_thread_win32-mt-s \
    -lws2_32 \
    -lmswsock \
    -lshlwapi

all: eth$(EXE_EXT)

obj/main.o: main.cpp
	$(CXX) $(CXX_FLAGS) -o $@ -c $< $(INCLUDE_PATH) $(LIB_PATH)

eth$(EXE_EXT): obj/main.o
	$(CXX) $(CXX_FLAGS) -o $@ obj/main.o $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) -v

clean:
	-rm -f obj/*.o eth$(EXE_EXT)
