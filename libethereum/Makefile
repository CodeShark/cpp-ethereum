CXX = x86_64-w64-mingw32-g++
AR = x86_64-w64-mingw32-ar

CXX_FLAGS = -Wall -DSTATICLIB -std=c++0x

HEADERS = \
    AddressState.h \
    BlockChain.h \
    BlockInfo.h \
    Client.h \
    Common.h \
    Dagger.h \
    Exceptions.h \
    FileSystem.h \
    Instruction.h \
    MemTrie.h \
    PeerNetwork.h \
    RLP.h \
    State.h \
    Transaction.h \
    TransactionQueue.h \
    TrieCommon.h \
    TrieDB.h \
    TrieHash.h \
    vector_ref.h

SOURCES = \
    AddressState.cpp \
    BlockChain.cpp \
    BlockInfo.cpp \
    Client.cpp \
    Common.cpp \
    Dagger.cpp \
    FileSystem.cpp  \
    MemTrie.cpp \
    PeerNetwork.cpp \
    RLP.cpp \
    State.cpp \
    Transaction.cpp \
    TransactionQueue.cpp \
    TrieCommon.cpp \
    TrieDB.cpp \
    TrieHash.cpp

OBJS = \
    obj/AddressState.o \
    obj/BlockChain.o \
    obj/BlockInfo.o \
    obj/Client.o \
    obj/Common.o \
    obj/Dagger.o \
    obj/FileSystem.o \
    obj/MemTrie.o \
    obj/PeerNetwork.o \
    obj/RLP.o \
    obj/State.o \
    obj/Transaction.o \
    obj/TransactionQueue.o \
    obj/TrieCommon.o \
    obj/TrieDB.o \
    obj/TrieHash.o

INCLUDE_PATH += \
    -I./ \
    -I/usr/x86_64-w64-ming32/include \
    -I../../cryptopp562 \
    -I../../secp256k1/include

#LIBS += \
    -lboost_system-mt-s \
    -lboost_filesystem-mt-s \
    -lboost_chrono-mt-s \
    -lboost_thread_win32-mt-s \
    -lws2_32 \
    -lmswsock \
    -lshlwapi

SECP256K1_OBJS = \
    ../../secp256k1/obj/secp256k1.o \
    ../../secp256k1/obj/field_5x52_asm.o \
    ../../secp256k1/libsecp256k1.a

all: $(OBJS) lib/libethereum.a

obj/%.o: %.cpp %.h
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(INCLUDE_PATH)

lib/libethereum.a: $(OBJS) $(SECP256K1_OBJS)
	$(AR) rcs $@ $^

clean:
	-rm -f obj/*.o
