
output: main.o Base.o CSV_Reader.o Edge.o Image_Rotate.o Node.o PPMI.o UCINET_DL_Filter.o Vertex.o Triangle.o Face.o PLY_Filter.o
	g++ main.o Base.o CSV_Reader.o Edge.o Image_Rotate.o Node.o PPMI.o UCINET_DL_Filter.o Vertex.o Triangle.o Face.o PLY_Filter.o -o output

main.o: main.cpp
	g++ -c main.cpp
Base.o: Base.cpp ../include/Base.h
	g++ -c Base.cpp

Edge.o: Edge.cpp ../include/Edge.h
	g++ -c Edge.cpp

Node.o: Node.cpp ../include/Node.h
	g++ -c Node.cpp

UCINET_DL_Filter.o: UCINET_DL_Filter.cpp ../include/UCINET_DL_Filter.h Base.cpp ../include/Base.h Node.cpp ../include/Node.h Edge.cpp ../include/Edge.h
	g++ -c UCINET_DL_Filter.cpp Base.cpp

CSV_Reader.o: CSV_Reader.cpp Base.cpp ../include/Base.h ../include/CSV_Reader.h
	g++ -c CSV_Reader.cpp Base.cpp

Image_Rotate.o: Image_Rotate.cpp Base.cpp ../include/Base.h ../include/Image_Rotate.h
	g++ -c Image_Rotate.cpp Base.cpp

PPMI.o:	PPMI.cpp Base.cpp ../include/Base.h ../include/PPMI.h
	g++ -c PPMI.cpp Base.cpp

Vertex.o: Vertex.cpp ../include/Vertex.h
	g++ -c Vertex.cpp

Triangle.o: Triangle.cpp Vertex.cpp ../include/Triangle.h ../include/Vertex.h 
	g++ -c Triangle.cpp
	
Face.o: Face.cpp Vertex.cpp Triangle.cpp Face.cpp ../include/Face.h ../include/Vertex.h ../include/Triangle.h
	g++ -c Face.cpp

PLY_Filter.o: PLY_Filter.cpp ../include/PLY_Filter.h Base.cpp ../include/Base.h ../include/Vertex.h Vertex.cpp ../include/Triangle.h Triangle.cpp ../include/Face.h Face.cpp
	g++ -c PLY_Filter.cpp Base.cpp

clean:
	rm *.o output


