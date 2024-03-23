all: makeLesson1


makeLesson1:
	 $(MAKE) all -C ./Lesson1

makerunLesson1:
	 $(MAKE) run -C ./Lesson1

makeStupidFFT:
	 $(MAKE) all -C ./StupidFFT

makerunStupidFFT:
	 $(MAKE) run -C ./StupidFFT




