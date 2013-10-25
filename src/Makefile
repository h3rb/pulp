BINARY = pulp
EXTENSIONS = *.h *.cpp *.c
CXX = g++ -std=c++0x
CXXFLAGS = -Wall -g3
HEADERS = $(OBJECTS:.o=.h)
LIBS = -lrt
OBJECTS = $(BINARY).o \
	macros.o moremath.o string_functions.o \
	Randoms.o \
	ZeroTypes.o TimeKeeper.o BinaryFile.o CommandLine.o \
	Indexed.o LinkedList.o ListItem.o Strings.o Numbers.o \
	TCPListener.o TCPIncoming.o TCPOutgoing.o bind_socket.o \
        Server.o Protocol.o OutputCodec.o ConfigFile.o \
	OutputProcessor.o OutputANSI.o OutputHTML.o \
	InputProcessor.o \
	Flag.o Statistic.o Modifier.o ModifiedStatistic.o \
	Template.o Entity.o \
	Material.o Prototype.o Prop.o \
	Skill.o Genetics.o Actor.o Player.o \
	Cue.o Blueprint.o Scene.o \
	Geology.o Geography.o \
	Culture.o Currency.o Nation.o Empire.o \
	Planet.o System.o Galaxy.o Dimension.o \
	Database.o
	

# ****************************************************
# Targets needed to bring the executable up to date

lmud:   $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(BINARY) $(OBJECTS) $(LIBS)

lmud.o: $(BINARY).cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(BINARY).cpp

# ****************************************************
# Clean, protecting Makefiles and source files.

clean:
	-chmod u-rw $(EXTENSIONS) Makefile
	rm -rf $(OBJECTS) $(BINARY)
	-chmod u+rw $(EXTENSIONS) Makefile

# ****************************************************
# make re   - rebuild macro

re:
	make clean
	make lmud

macros.o: macros.h

moremath.o: moremath.h macros.h

string_functions.o: string_functions.h macros.h

ListItem.o: ListItem.h string_functions.h macros.h moremath.h

LinkedList.o: LinkedList.h ListItem.h macros.h moremath.h string_functions.h

Strings.o: Strings.h LinkedList.h string_functions.h

Numbers.o: Numbers.h Strings.h LinkedList.h

Flag.o: Flag.h LinkedList.h

Statistic.o: Statistic.h LinkedList.h ListItem.h

Randoms.o: Randoms.h LinkedList.h ListItem.h ZeroTypes.h

Indexed.o: Indexed.h macros.h moremath.h string_functions.h

BinaryFile.o: BinaryFile.h Strings.h LinkedList.h ListItem.h

ZeroTypes.o: ZeroTypes.h macros.h

TimeKeeper.o: TimeKeeper.h ZeroTypes.h

TCPIncoming.o: TCPIncoming.h Strings.h

TCPOutgoing.o: TCPOutgoing.h LinkedList.h

TCPListener.o: TCPListener.h TCPIncoming.h bind_socket.h

Server.o: Server.h TCPListener.h 

InSession.o: InSession.h TCPIncoming.h LinkedList.h

Protocol.o: Protocol.h Strings.h LinkedList.h

OutputCodec.o: OutputCodec.h Strings.h LinkedList.h

CommandLine.o: Strings.h

ConfigFile.o: Strings.h string_functions.h

OutputProcessor.o: OutputProcessor.h Strings.h string_functions.h

OutputANSI.o: OutputANSI.h OutputProcessor.h

OutputHTML.o: OutputHTML.h OutputProcessor.h

InputProcessor.o: InputProcessor.h Strings.h string_functions.h

Template.o: Template.h ListItem.h

Entity.o: Entity.h Template.h

Material.o: Material.h LinkedList.h

Prototype.o: Prototype.h Template.h

Blueprint.o: Blueprint.h Cue.h Template.h

Genetics.o: Genetics.h Template.h

Geology.o: Geology.h Template.h

Geography.o: Geography.h Weather.h Geology.h

Prop.o: Prop.h Prototype.h Material.h

Modifier.o: Modifier.h Numbers.h

Statistic.o: Statistic.h LinkedList.h

ModifiedStatistic.o: ModifiedStatistic.h Modifier.h Statistic.h

Skill.o: Skill.h ModifiedStatistic.h

Class.o: Class.h LinkedList.h Skill.h

Archetype.o: Archetype.h LinkedList.h

Actor.o: Actor.h Genetics.h AcquiredSkill.h

Player.o: Player.h Actor.h Time.h

Scene.o: Scene.h Blueprint.h

Currency.o: Currency.h LinkedList.h

Culture.o: Culture.h LinkedList.h

Nation.o: Nation.h Currency.h LinkedList.h

Empire.o: Empire.h Nation.h

Statistic.o: Statistic.h Numbers.h

Modifier.o: Modifier.h LinkedList.h

ModifiedStatistic.o: ModifiedStatistic.h Modifier.h Statistic.h

Cue.o: Cue.h Actor.h Prop.h LinkedList.h

Planet.o: Planet.h Nation.h

System.o: System.h Planet.h

Galaxy.o: Galaxy.h System.h

Dimension.o: Dimension.h System.h

Time.o: Time.h ListItem.h Timekeeper.h ZeroTypes.h

Database.o: Database.h Dimension.h Galaxy.h System.h Planet.h Geography.h Empire.h Nation.h Scene.h Player.h Actor.h Prop.h
