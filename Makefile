libprotobuf_path=/opt/libprotobuf-mutator-1.1/

all:
	protoc person_data.proto --cpp_out=fuzzer
	clang++ -w -c library.cpp -o library.o
	clang++ $(libprotobuf_path)src/libfuzzer/libfuzzer_mutator.cc $(libprotobuf_path)src/libfuzzer/libfuzzer_macro.cc fuzzer/person_data.pb.cc fuzzer/harness.cpp library.o -o protobuf_fuzz -I /usr/local/include/libprotobuf-mutator/ -lprotobuf -lprotobuf-mutator -fsanitize=address,fuzzer

  