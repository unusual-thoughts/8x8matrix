#include "Tlc5947.h"
const uint8_t PROGMEM nyan[(8 * 8 * 3 + 1) * 32] =
	("\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"
	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\0""3f\0""3f\0""3f"
	 "\0""3f\0""3f\0""3f\0""3f\377\242\240\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\231\231\231\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231"
	 "\0\0\0\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\377"
	 "\242\240\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231"
	 "\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0\0\0\231\231\231\0""3f\0""3f\0""3f\0""3f"
	 "\0""3f\0""3f\231\231\231\377\242\240\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231"
	 "\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231"
	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\0\0\0\231\231\231\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\377\242\240\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\231\231\231\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\377\314\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\377\314\231\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231"
	 "\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\0\0\0\231\231"
	 "\231\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\377\242\240\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\0""3f\0""3f\0""3f\0""3f"
	 "\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\314\231\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\3728\214\377\314\231\231\231\231\0""3f\0""3f"
	 "\0""3f\0""3f\0""3f\231\231\231\231\231\231\231\231\231\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0\0\0\231\231\231\0\0\0\231\231\231\0""3f\0""3f\0""3f\0""3f\231"
	 "\231\231\231\231\231\231\231\231\377\242\240\0""3f\0""3f\0""3f\0""3f\231\231"
	 "\231\231\231\231\231\231\231\0""3f\0""3f\0""3f\0""3f\0""3f\377\314\231\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"

	 "\377\314\231\377\314\231\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\231\377\372"
	 "8\214\377\314\231\0""3f\0""3f\0""3f\0""3f\0""3f\231\231\231\377\231\377\377"
	 "\314\231\231\231\231\0""3f\0""3f\0""3f\0""3f\231\231\231\231\231\231\231\231"
	 "\231\231\231\231\0""3f\0""3f\0""3f\0""3f\231\231\231\0\0\0\231\231\231\0\0"
	 "\0\231\231\231\0""3f\0""3f\0""3f\231\231\231\231\231\231\231\231\231\231\231"
	 "\231\377\242\240\0""3f\0""3f\0""3f\231\231\231\231\231\231\231\231\231\231"
	 "\231\231\0""3f\0""3f\0""3f\0""3f\231\231\231\0""3f\231\231\231\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f"

	 "\377\314\231\377\314\231\377\314\231\0""3f\0""3f\0""3f\0""3f\0""3f\377\231"
	 "\377\377\231\377\3728\214\377\314\231\0""3f\0""3f\0""3f\0""3f\377\231\377"
	 "\377\231\377\231\231\231\377\314\231\0""3f\231\231\231\0""3f\0""3f\377\231"
	 "\377\377\231\377\231\231\231\231\231\231\231\231\231\231\231\231\0""3f\0""3"
	 "f\377\231\377\231\231\231\231\231\231\0\0\0\231\231\231\0\0\0\231\231\231"
	 "\0""3f\377\231\377\377\242\240\231\231\231\231\231\231\231\231\231\231\231"
	 "\231\377\242\240\0""3f\377\314\231\377\314\231\231\231\231\231\231\231\231"
	 "\231\231\231\231\231\0""3f\0""3f\0""3f\231\231\231\0""3f\231\231\231\0""3"
	 "f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\314\231\377\314\231\377"
	 "\314\231\377\314\231\0""3f\0""3f\0""3f\0""3f\3728\214\377\231\377\377\231"
	 "\377\3728\214\377\314\231\0""3f\0""3f\0""3f\377\231\377\377\231\377\377\231"
	 "\377\231\231\231\377\314\231\0""3f\231\231\231\0""3f\377\231\377\377\231\377"
	 "\377\231\377\231\231\231\231\231\231\231\231\231\231\231\231\0""3f\377\231"
	 "\377\377\231\377\231\231\231\231\231\231\0\0\0\231\231\231\0\0\0\231\231\231"
	 "\3728\214\377\231\377\377\242\240\231\231\231\231\231\231\231\231\231\231"
	 "\231\231\377\242\240\377\314\231\377\314\231\377\314\231\231\231\231\231\231"
	 "\231\231\231\231\231\231\231\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\314\231\377\314\231\377"
	 "\314\231\377\314\231\377\314\231\0""3f\0""3f\0""3f\377\231\377\3728\214\377"
	 "\231\377\377\231\377\3728\214\377\314\231\0""3f\0""3f\377\231\377\377\231"
	 "\377\377\231\377\377\231\377\231\231\231\377\314\231\0""3f\231\231\231\377"
	 "\231\377\377\231\377\377\231\377\377\231\377\231\231\231\231\231\231\231\231"
	 "\231\231\231\231\377\231\377\377\231\377\377\231\377\231\231\231\231\231\231"
	 "\0\0\0\231\231\231\0\0\0\377\231\377\3728\214\377\231\377\377\242\240\231"
	 "\231\231\231\231\231\231\231\231\231\231\231\377\314\231\377\314\231\377\314"
	 "\231\377\314\231\231\231\231\231\231\231\231\231\231\231\231\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\314\231\377\314\231\377"
	 "\314\231\377\314\231\377\314\231\377\314\231\0""3f\0""3f\377\231\377\377\231"
	 "\377\3728\214\377\231\377\377\231\377\3728\214\377\314\231\0""3f\377\231\377"
	 "\377\231\377\377\231\377\377\231\377\231\231\231\377\231\377\377\314\231\231"
	 "\231\231\3728\214\377\231\377\377\231\377\377\231\377\231\231\231\231\231"
	 "\231\231\231\231\231\231\231\377\231\377\377\231\377\377\231\377\231\231\231"
	 "\231\231\231\0\0\0\231\231\231\0\0\0\377\231\377\377\231\377\3728\214\377"
	 "\242\240\231\231\231\231\231\231\231\231\231\231\231\231\377\314\231\377\314"
	 "\231\377\314\231\377\314\231\231\231\231\231\231\231\231\231\231\231\231\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\314\231\377"
	 "\314\231\377\314\231\377\314\231\377\314\231\377\314\231\0""3f\377\314\231"
	 "\377\231\377\377\231\377\3728\214\377\231\377\231\231\231\3728\214\377\314"
	 "\231\377\314\231\377\231\377\377\231\377\377\231\377\377\231\377\231\231\231"
	 "\231\231\231\231\231\231\377\314\231\3728\214\377\231\377\377\231\377\231"
	 "\231\231\231\231\231\0\0\0\231\231\231\377\314\231\377\231\377\377\231\377"
	 "\377\231\377\377\242\240\231\231\231\231\231\231\231\231\231\377\314\231\377"
	 "\231\377\377\231\377\3728\214\377\231\377\231\231\231\231\231\231\231\231"
	 "\231\231\231\231\377\314\231\377\314\231\377\314\231\377\314\231\377\314\231"
	 "\377\314\231\0""3f"

	 "\0""3f\0""3f\377\314\231\377\314\231\377\314\231\377\314\231\377\314\231\377"
	 "\314\231\377\30\0\377\314\231\377\231\377\377\231\377\3728\214\377\231\377"
	 "\377\231\377\3728\214\377\232\0\377\314\231\377\231\377\377\231\377\377\231"
	 "\377\377\231\377\231\231\231\377\231\377\377\357\0\377\314\231\3728\214\377"
	 "\231\377\377\231\377\377\231\377\231\231\231\231\231\231\231\231\231\377\314"
	 "\231\377\231\377\377\231\377\377\231\377\231\231\231\231\231\231\0\0\0\231"
	 "\231\231\377\314\231\377\231\377\377\231\377\3728\214\377\242\240\231\231"
	 "\231\231\231\231\231\231\231\231\231\231\377\314\231\377\314\231\377\314\231"
	 "\377\314\231\231\231\231\231\231\231\231\231\231\0""3f\0""3f\231\231\231\0"
	 """3f\0""3f\231\231\231\0""3f"

	 "\0""3f\0""3f\0""3f\377\314\231\377\314\231\377\314\231\377\314\231\377\314"
	 "\231\377\30\0\377\30\0\377\314\231\377\231\377\377\231\377\3728\214\377\231"
	 "\377\377\231\377\377\232\0\377\232\0\377\314\231\377\231\377\377\231\377\377"
	 "\231\377\377\231\377\377\231\377\377\357\0\377\357\0\377\314\231\3728\214"
	 "\377\231\377\377\231\377\377\231\377\377\231\377\231\231\231\231\231\231\377"
	 "\314\231\377\231\377\377\231\377\377\231\377\377\231\377\231\231\231\0\214"
	 "\377\231\231\231\377\314\231\377\231\377\377\231\377\3728\214\377\231\377"
	 "\377\242\240iB\377iB\377\231\231\231\377\314\231\377\314\231\377\314\231\377"
	 "\314\231\377\314\231\0""3f\0""3f\231\231\231\0""3f\231\231\231\0""3f\0""3"
	 "f\231\231\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30\0\377\30"
	 "\0\0""3f\377\314\231\377\314\231\377\314\231\377\314\231\377\232\0\377\232"
	 "\0\377\232\0\377\314\231\377\231\377\377\231\377\3728\214\377\231\377\377"
	 "\357\0\377\357\0\377\357\0\377\314\231\377\231\377\377\231\377\377\231\377"
	 "\377\231\377!\335\0!\335\0!\335\0\377\314\231\3728\214\377\231\377\377\231"
	 "\377\377\231\377\231\231\231\231\231\231\231\231\231\377\314\231\377\231\377"
	 "\377\231\377\377\231\377\377\231\377iB\377iB\377\231\231\231\377\314\231\377"
	 "\231\377\377\231\377\3728\214\377\231\377\0""3f\0""3f\0""3f\231\231\231\377"
	 "\314\231\377\314\231\377\314\231\377\314\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30\0\377"
	 "\30\0\0""3f\377\314\231\377\314\231\377\314\231\377\30\0\377\232\0\377\232"
	 "\0\377\232\0\377\314\231\377\231\377\377\231\377\3728\214\377\232\0\377\357"
	 "\0\377\357\0\377\357\0\377\314\231\377\231\377\377\231\377\377\231\377\377"
	 "\357\0!\335\0!\335\0!\335\0\377\314\231\3728\214\377\231\377\377\231\377!"
	 "\335\0\0\214\377\231\231\231\231\231\231\377\314\231\377\231\377\377\231\377"
	 "\377\231\377\0\214\377\231\231\231iB\377\231\231\231\377\314\231\377\231\377"
	 "\377\231\377\3728\214iB\377\0""3f\0""3f\0""3f\231\231\231\377\314\231\377"
	 "\314\231\377\314\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30\0\377"
	 "\30\0\0""3f\0""3f\377\314\231\377\314\231\377\30\0\377\232\0\377\232\0\377"
	 "\232\0\377\30\0\377\314\231\377\231\377\377\231\377\377\232\0\377\357\0\377"
	 "\357\0\377\357\0\377\232\0\377\314\231\377\231\377\377\231\377\377\357\0!"
	 "\335\0!\335\0!\335\0\377\357\0\377\314\231\3728\214\377\231\377!\335\0\0\214"
	 "\377\231\231\231\231\231\231\231\231\231\377\314\231\377\231\377\377\231\377"
	 "\0\214\377iB\377iB\377iB\377\231\231\231\377\314\231\377\231\377\377\231\377"
	 "iB\377\0""3f\0""3f\0""3f\231\231\231\231\231\231\377\314\231\377\314\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377"
	 "\30\0\377\30\0\0""3f\0""3f\377\314\231\377\30\0\377\30\0\377\232\0\377\232"
	 "\0\377\232\0\377\30\0\377\314\231\377\231\377\377\232\0\377\232\0\377\357"
	 "\0\377\357\0\377\357\0\377\232\0\377\314\231\377\231\377\377\357\0\377\357"
	 "\0!\335\0\231\231\231!\335\0\377\357\0\377\314\231\3728\214!\335\0!\335\0"
	 "\0\214\377\231\231\231\231\231\231\231\231\231\377\314\231\377\231\377\0\214"
	 "\377\0\214\377iB\377iB\377iB\377\231\231\231\377\314\231\377\231\377iB\377"
	 "iB\377\0""3f\0""3f\0""3f\231\231\231\231\231\231\377\314\231"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377"
	 "\30\0\377\30\0\0""3f\0""3f\377\314\231\377\30\0\377\30\0\377\232\0\377\232"
	 "\0\377\232\0\377\30\0\377\30\0\377\314\231\377\232\0\377\232\0\377\357\0\377"
	 "\357\0\231\231\231\231\231\231\377\232\0\377\314\231\377\357\0\377\357\0!"
	 "\335\0!\335\0!\335\0\231\231\231\231\231\231\377\314\231!\335\0!\335\0\0\214"
	 "\377\0\214\377\0\214\377!\335\0\231\231\231\377\314\231\0\214\377\0\214\377"
	 "iB\377iB\377iB\377\0\214\377\231\231\231\231\231\231iB\377iB\377\0""3f\0""3"
	 "f\0""3fiB\377\231\231\231\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30"
	 "\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377\232\0\377"
	 "\232\0\377\232\0\377\30\0\377\30\0\0""3f\377\232\0\377\232\0\377\357\0\377"
	 "\357\0\231\231\231\377\232\0\377\232\0\377\357\0\377\357\0\377\357\0!\335"
	 "\0!\335\0\231\231\231\231\231\231\231\231\231\0""3f!\335\0!\335\0\0\214\377"
	 "\0\214\377\0\214\377!\335\0\231\231\231\0\214\377\0\214\377\0\214\377iB\377"
	 "iB\377iB\377\0\214\377\231\231\231\0""3fiB\377iB\377\0""3f\0""3f\0""3fiB\377"
	 "iB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30"
	 "\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377\232\0\377"
	 "\232\0\377\232\0\377\30\0\377\30\0\0""3f\377\232\0\377\232\0\377\357\0\377"
	 "\357\0\377\357\0\377\232\0\377\232\0\377\357\0\377\357\0\377\357\0!\335\0"
	 "!\335\0!\335\0\377\357\0\377\357\0\0""3f!\335\0!\335\0\0\214\377\0\214\377"
	 "\0\214\377\231\231\231\231\231\231\0\214\377\0\214\377\0\214\377iB\377iB\377"
	 "iB\377\0\214\377\0\214\377\0""3fiB\377iB\377\0""3f\0""3f\0""3fiB\377iB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377"
	 "\30\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377\232\0\377"
	 "\232\0\377\232\0\377\30\0\0""3f\0""3f\377\232\0\377\232\0\377\357\0\377\357"
	 "\0\377\357\0\377\232\0\0""3f\377\357\0\377\357\0\377\357\0!\335\0!\335\0!"
	 "\335\0\377\357\0\0""3f\0""3f!\335\0!\335\0\0\214\377\0\214\377\0\214\377!"
	 "\335\0\0""3f\0\214\377\0\214\377\0\214\377iB\377iB\377iB\377\231\231\231\0"
	 """3f\0""3fiB\377iB\377\0""3f\0""3f\0""3fiB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377"
	 "\30\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377\232\0\377"
	 "\232\0\377\232\0\377\30\0\0""3f\0""3f\377\232\0\377\232\0\377\357\0\377\357"
	 "\0\377\357\0\377\232\0\0""3f\377\357\0\377\357\0\377\357\0!\335\0!\335\0!"
	 "\335\0\377\357\0\0""3f\0""3f!\335\0!\335\0\0\214\377\0\214\377\0\214\377!"
	 "\335\0\0""3f\0\214\377\0\214\377\0\214\377iB\377iB\377iB\377\0\214\377\0""3"
	 "f\0""3fiB\377iB\377\0""3f\0""3f\0""3fiB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\377\30\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377"
	 "\232\0\377\232\0\377\232\0\0""3f\0""3f\0""3f\377\232\0\377\232\0\377\357\0"
	 "\377\357\0\377\357\0\0""3f\0""3f\377\357\0\377\357\0\377\357\0!\335\0!\335"
	 "\0!\335\0\0""3f\0""3f\0""3f!\335\0!\335\0\0\214\377\0\214\377\0\214\377\0"
	 """3f\0""3f\0\214\377\0\214\377\0\214\377iB\377iB\377iB\377\0""3f\0""3f\0""3"
	 "fiB\377iB\377\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\377\30\0\377\30\0\377\30\0\0""3f\0""3f\377\30\0\377\30\0\377\30\0\377"
	 "\232\0\377\232\0\377\232\0\0""3f\0""3f\0""3f\377\232\0\377\232\0\377\357\0"
	 "\377\357\0\377\357\0\0""3f\0""3f\377\357\0\377\357\0\377\357\0!\335\0!\335"
	 "\0!\335\0\0""3f\0""3f\0""3f!\335\0!\335\0\0\214\377\0\214\377\0\214\377\0"
	 """3f\0""3f\0\214\377\0\214\377\0\214\377iB\377iB\377iB\377\0""3f\0""3f\0""3"
	 "fiB\377iB\377\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\377\30\0\377\30\0\0""3f\0""3f\0""3f\377\30\0\377\30\0\377\30\0"
	 "\377\232\0\377\232\0\0""3f\0""3f\0""3f\0""3f\377\232\0\377\232\0\377\357\0"
	 "\377\357\0\0""3f\0""3f\0""3f\377\357\0\377\357\0\377\357\0!\335\0!\335\0\0"
	 """3f\0""3f\0""3f\0""3f!\335\0!\335\0\0\214\377\0\214\377\0""3f\0""3f\0""3"
	 "f\0\214\377\0\214\377\0\214\377iB\377iB\377\0""3f\0""3f\0""3f\0""3fiB\377"
	 "iB\377\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\377\30\0\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30\0\377\30"
	 "\0\377\232\0\0""3f\0""3f\0""3f\0""3f\0""3f\377\232\0\377\232\0\377\357\0\0"
	 """3f\0""3f\0""3f\0""3f\377\357\0\377\357\0\377\357\0!\335\0\0""3f\0""3f\0"
	 """3f\0""3f\0""3f!\335\0!\335\0\0\214\377\0""3f\0""3f\0""3f\0""3f\0\214\377"
	 "\0\214\377\0\214\377iB\377\0""3f\0""3f\0""3f\0""3f\0""3fiB\377iB\377\0""3"
	 "f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30\0\377"
	 "\30\0\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\232\0\377\232\0\0""3f\0""3f"
	 "\0""3f\0""3f\0""3f\377\357\0\377\357\0\377\357\0\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f!\335\0!\335\0\0""3f\0""3f\0""3f\0""3f\0""3f\0\214\377\0\214\377"
	 "\0\214\377\0""3f\0""3f\0""3f\0""3f\0""3f\0""3fiB\377iB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0\377\30"
	 "\0\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\232\0\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\377\357\0\377\357\0\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f!\335\0\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0\214\377\0\214\377\0""3f"
	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3fiB\377"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\377\30\0"
	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\377\357\0\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0\214\377\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f"

	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f"
	 "\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0"
	 """3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3f\0""3"
	 "f\0""3f\0""3f"
	);

const uint8_t PROGMEM font[95 * 8] =
{
	0,   0,   0,   0,   0,   0,   0,   0,
	2,   2,   2,   2,   2,   2,   0,   2,
	5,   5,   5,   0,   0,   0,   0,   0,
	20,  20,  63,  10,  10,  63,  10,  10,
	0,   4,  30,   5,  14,  20,  15,   0,
	34,  37,  21,  18,  72, 168, 164,  68,
	12,  18,  18,  12,  74,  49,  49,  78,
	1,   1,   1,   0,   0,   0,   0,   0,
	4,   2,   1,   1,   1,   1,   2,   4,
	1,   2,   4,   4,   4,   4,   2,   1,
	4,  21,  14,  21,   4,   0,   0,   0,
	0,   0,   4,   4,  31,   4,   4,   0,
	0,   0,   0,   0,   0,   2,   2,   1,
	0,   0,   0,   0,   0,   7,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   2,
	4,   4,   2,   2,   2,   2,   1,   1,
	14,  17,  17,  17,  17,  17,  17,  14,
	8,  12,  10,   8,   8,   8,   8,   8,
	14,  17,  16,   8,   4,   2,   1,  31,
	14,  17,  16,  12,  16,  16,  17,  14,
	16,  24,  20,  18,  17,  63,  16,  16,
	31,   1,   1,  15,  16,  16,  17,  14,
	14,  17,   1,  15,  17,  17,  17,  14,
	31,  16,   8,   8,   4,   4,   2,   2,
	14,  17,  17,  14,  17,  17,  17,  14,
	14,  17,  17,  17,  30,  16,  16,  14,
	0,   0,   0,   2,   0,   0,   0,   2,
	0,   0,   2,   0,   0,   2,   2,   1,
	0,   0,  48,  12,   3,  12,  48,   0,
	0,   0,   0,  31,   0,  31,   0,   0,
	0,   0,   3,  12,  48,  12,   3,   0,
	14,  17,  17,   8,   4,   4,   0,   4,
	60,  66, 185, 165, 165, 121, 130, 124,
	8,   8,  20,  20,  34,  62,  65,  65,
	30,  34,  34,  30,  34,  34,  34,  30,
	60,  66,   1,   1,   1,   1,  66,  60,
	30,  34,  66,  66,  66,  66,  34,  30,
	62,   2,   2,  30,   2,   2,   2,  62,
	62,   2,   2,  30,   2,   2,   2,   2,
	60,  66,   1,   1, 113,  65,  66,  60,
	66,  66,  66, 126,  66,  66,  66,  66,
	2,   2,   2,   2,   2,   2,   2,   2,
	8,   8,   8,   8,   8,   8,   9,   6,
	34,  18,  10,   6,  10,  18,  34,  66,
	2,   2,   2,   2,   2,   2,   2,  62,
	130, 198, 198, 170, 170, 146, 146, 130,
	34,  38,  38,  42,  42,  50,  50,  34,
	28,  34,  65,  65,  65,  65,  34,  28,
	30,  34,  34,  34,  30,   2,   2,   2,
	28,  34,  65,  65,  65,  65,  50, 124,
	62,  66,  66,  66,  62,  18,  34,  66,
	28,  34,   2,  12,  16,  32,  34,  28,
	31,   4,   4,   4,   4,   4,   4,   4,
	66,  66,  66,  66,  66,  66,  66,  60,
	65,  65,  34,  34,  20,  20,   8,   8,
	130, 146, 146, 170, 170,  68,  68,  68,
	34,  20,  20,   8,   8,  20,  20,  34,
	17,  17,  10,  10,   4,   4,   4,   4,
	63,  32,  16,   8,   4,   2,   1,  63,
	6,   2,   2,   2,   2,   2,   2,   6,
	1,   1,   2,   2,   2,   2,   4,   4,
	3,   2,   2,   2,   2,   2,   2,   3,
	4,  10,  10,  17,  17,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,  63,
	1,   2,   0,   0,   0,   0,   0,   0,
	0,   0,   0,  14,  17,  30,  17,  30,
	2,   2,   2,  30,  34,  34,  34,  30,
	0,   0,   0,  14,  17,   1,  17,  14,
	16,  16,  16,  30,  17,  17,  17,  30,
	0,   0,   0,  14,  17,  31,   1,  30,
	4,   2,   2,   7,   2,   2,   2,   2,
	0,   0,   0,  30,  17,  30,  16,  14,
	2,   2,   2,  30,  34,  34,  34,  34,
	0,   2,   0,   2,   2,   2,   2,   2,
	0,   2,   0,   2,   2,   2,   2,   1,
	2,   2,   2,  18,  10,   6,  10,  18,
	2,   2,   2,   2,   2,   2,   2,   2,
	0,   0,   0, 110, 146, 146, 146, 146,
	0,   0,   0,  30,  34,  34,  34,  34,
	0,   0,   0,  14,  17,  17,  17,  14,
	0,   0,   0,  30,  34,  34,  30,   2,
	0,   0,   0,  30,  17,  17,  30,  16,
	0,   0,   0,  26,   6,   2,   2,   2,
	0,   0,   0,  14,   1,   6,   8,   7,
	0,   2,   2,   7,   2,   2,   2,   4,
	0,   0,   0,  34,  34,  34,  34,  60,
	0,   0,   0,  17,  17,  10,  10,   4,
	0,   0,   0,  73,  73,  85,  34,  34,
	0,   0,   0,  17,  10,   4,  10,  17,
	0,   0,   0,  17,  10,  10,   4,   3,
	0,   0,   0,  31,   8,   4,   2,  31,
	12,   2,   2,   2,   1,   2,   2,  12,
	2,   2,   2,   2,   2,   2,   2,   2,
	3,   4,   4,   8,   8,   4,   4,   3,
	0,   0,   0,  20,  10,   0,   0,   0
};

const uint8_t PROGMEM font_width[95] =
{
	3, 2, 3, 6, 5, 8, 7, 1, 3, 3, 5, 5, 2, 3, 2, 3,
	5, 4, 5, 5, 6, 5, 5, 5, 5, 5, 2, 2, 6, 5, 6, 5,
	8, 7, 6, 7, 7, 6, 6, 7, 7, 2, 4, 7, 6, 8, 6, 7,
	6, 7, 7, 6, 5, 7, 7, 8, 6, 5, 6, 3, 3, 2, 5, 6,
	2, 5, 6, 5, 5, 5, 3, 5, 6, 2, 2, 5, 2, 8, 6, 5,
	6, 5, 5, 4, 3, 6, 5, 7, 5, 5, 5, 4, 2, 4, 5
};

const uint8_t PROGMEM creeper[8 * 8 * 3 + 1] =
	("\267\327\266\10\245\10\15\271\15}\317~\307\325\310-\327.(\316(S\207S>\215"
	 "=\16\277\15""1\3061EyEPsQ9\300:\26\311\27\273\315\273\22\253\22>b=.N,8\271"
	 "90\2021\30;\27Be@\314\330\314\23\313\24""4X5#,\"\17\303\17>\312?2110;0\24"
	 "\276\24\223\336\224J\303K|\306}(Y(.]-\253\314\254A\205C\15\276\15\312\346"
	 "\312!\206!!W!\20\10\16\4\0\3)_*\33\311\34\237\334\236\275\377\274h\266h\12"
	 "\40\11\14\27\13\24\32\23\11\"\10""7\2709U\227V,\331,k\332j?g>s\320s\265\366"
	 "\265C_A\2]\1\32\273\32");

const uint8_t PROGMEM bonhomme[8 * 8 * 3 + 1] =
	("B6&)\40\21)\37\20'\35\15(\35\15(\36\17)!\23>2$\40\26\5:*\27@/\34H4\40V:!Q"
	 "8\"=*\31!\27\10F5$\252z[\314\230r\304\224~\274\214t\313\225q\244lKN7$\263"
	 "\212s\303\232\210\251\177z\267\206t\260\202l\257\203~\262\206q\247w\\\316"
	 "\240\204\352\345\357i[\263\237h]\252xahX\256\340\334\353\306\236\201\250r"
	 "U\277\213v\247xvrD7sE6\251yl\261\177b\216cE\223^B\213R1X1\22{B3\177C5\\2\24"
	 "\200N+\203S7\203\\ErK2F'\22O*\30R.\33J)\26\202X?\216eM");

const uint8_t PROGMEM pig[8 * 8 * 3 + 1] =
	("\345\235\232\347\216\217\346\215\220\347\213\214\346\215\210\346\216\214\344"
	 "\212\214\342\217\217\364\224\223\344\202\202\344\211\207\350\217\212\344\206"
	 "\204\341\203\177\345\205\202\365\215\216\326\217\215\346\227\225\346\211\205"
	 "\351\214\214\346\204\204\336xr\343\216\213\322\200\2033//\353\336\337\373"
	 "\247\252\346\211\212\344\207\204\362\222\217\355\334\334846\307{\177\346\233"
	 "\237\333\243\241\343\252\244\345\242\242\323\224\221\337\233\230\304~}\377"
	 "\243\242\327tzq?>\330\211\205\337\211\212q=>\317rr\377\240\232\351\224\222"
	 "\341\206\210\262YU\306mi\307ih\262TR\340\203\200\345\212\211\341\211\210\344"
	 "\215\215\345\210\206\343\224\216\342\211\211\345\205\202\350\224\221\343\223"
	 "\224");

const uint8_t PROGMEM maison[8 * 8 * 3 + 1] =
	("\14\\\222\14\\\222\14\\\222\377\0\0\14\\\222\14\\\222\14\\\222\14\\\222+p"
	 "\240+p\237\377\0\0\377\0\0\377\0\0+p\237*p\237*p\237O\210\257\377\0\0\377"
	 "\0\0\377\0\0\377\0\0\377\0\0N\207\257M\207\256r\237\276\0\0\0\377\377\377"
	 "\377\377\377\377\377\377\0\0\0r\236\276q\236\276\244\300\323\0\0\0\377\377"
	 "\377\377\377\377\377\377\377\0\0\0\242\276\323\243\276\323\350\354\361\0\0"
	 "\0\0\0\0\0\0\0\0\0\0\0\0\0\346\353\360\346\353\360`\255c_\254c`\253c`\253"
	 "c`\253c_\252b`\252b_\253b9\206B9\205B9\205C:\206C:\206C9\206C:\207C;\206D");

const uint8_t PROGMEM arcenciel[8 * 8 * 3 + 1] =
	("\350\10\320\350\10\320\350\10\320\350\10\320\350\10\320\350\10\320\350\10"
	 "\320\350\10\320\350\10\320M\10\350M\10\350M\10\350M\10\350M\10\350M\10\350"
	 "\350\10\320\350\10\320M\10\350\10\350G\10\350G\10\350G\10\350GM\10\350\350"
	 "\10\320\350\10\320M\10\350\10\350G\350\10\10\350\10\10\10\350GM\10\350\350"
	 "\10\320\350\10\320M\10\350\10\350G\350\10\10\350\10\10\10\350GM\10\350\350"
	 "\10\320\350\10\320M\10\350\10\350G\10\350G\10\350G\10\350GM\10\350\350\10"
	 "\320\350\10\320M\10\350M\10\350M\10\350M\10\350M\10\350M\10\350\350\10\320"
	 "\350\10\320\350\10\320\350\10\320\350\10\320\350\10\320\350\10\320\350\10"
	 "\320\350\10\320");

const uint8_t PROGMEM jojo[8 * 8 * 3 + 1] =
	("\351\324]\351\324]\351\324]\351\324]\351\324]\351\324]\351\324]\351\324]\351"
	 "\324]\351\324]\352\332\264\352\332\264\352\332\264\352\332\264\351\324]\351"
	 "\324]\351\324]\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264"
	 "\352\332\264\351\324]\352\332\264\370\377\377;\274\267\352\332\264\352\332"
	 "\264;\274\267\370\377\377\352\332\264\352\332\264\352\332\264\352\332\264"
	 "\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264\352"
	 "\332\264\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264\352\332"
	 "\264\352\332\264\352\332\264\352\332\264\377\0\0\377\0\0\352\332\264\352\332"
	 "\264\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264\352\332\264"
	 "\352\332\264\352\332\264\352\332\264");

const uint8_t PROGMEM zombie[8 * 8 * 3 + 1] =
	("X\202JKs=Ow>Eo9Ah4El9Kr>UwIAl3Dn6Gp8P\177?\\\226A\\\220CIq8=f0NvAj\225Wt\235"
	 "`v\232bs\230\\w\241`b\217JU\202Dl\214\\a\177P^|Oo\215Zh\207Tc\201QOs<\\\204"
	 "Io\217]$%\"##\40f\207Nl\217U&*$\35!\33c\203SZ\205C_\202Ie\177O?X*?Y+[\200"
	 "HIv6Go6Gp2M}7Ir4He,Fd*Ai.Fw2<e*Ih9:]*<`,Dg2Im7>a/Il7Oq?");

//*
const uint8_t PROGMEM gamma[] =
{
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
	2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
	5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
	10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
	17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
	25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
	37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
	51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
	69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
	90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
	115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
	144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
	177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
	215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

//*/

// CIELAB Bash one-liner
// for x in {0..255}; do if [ `echo "$x / 255 <= 0.08856"|bc -l` -eq 1 ]; then echo "(($x / 255) * 4095) / 9.033"|bc -l|cut -d "." -f1|tr "\n" ","; else echo "((($x / 255 + 0.16) / 1.16) ^ 3) * 4095"|bc -l|cut -d "." -f1| tr "\n" ","; fi; done

//*
const uint16_t PROGMEM cielab_12bit[] =
{
	0,   1,   3,   5,   7,   8,  10,  12,  14,  16,  17,  19,  21,  23,  24,  26,
	28,  30,  32,  33,  35,  37,  39,  41,  43,  45,  47,  49,  51,  53,  56,  58,
	61,  63,  66,  68,  71,  74,  77,  80,  83,  86,  89,  93,  96,  99, 103, 107,
	110, 114, 118, 122, 126, 130, 134, 139, 143, 148, 152, 157, 162, 166, 171, 176,
	182, 187, 192, 198, 203, 209, 215, 221, 227, 233, 239, 245, 252, 258, 265, 272,
	278, 285, 292, 300, 307, 314, 322, 330, 338, 346, 354, 362, 370, 378, 387, 396,
	405, 414, 423, 432, 441, 451, 460, 470, 480, 490, 500, 510, 521, 531, 542, 553,
	564, 575, 586, 598, 609, 621, 633, 645, 657, 670, 682, 695, 708, 721, 734, 747,
	760, 774, 788, 802, 816, 830, 845, 859, 874, 889, 904, 919, 935, 950, 966, 982,
	998, 1014, 1031, 1047, 1064, 1081, 1098, 1116, 1133, 1151, 1169, 1187, 1205, 1224, 1243, 1261,
	1281, 1300, 1319, 1339, 1359, 1379, 1399, 1419, 1440, 1461, 1482, 1503, 1524, 1546, 1568, 1590,
	1612, 1634, 1657, 1680, 1703, 1726, 1749, 1773, 1797, 1821, 1845, 1870, 1895, 1920, 1945, 1970,
	1996, 2022, 2048, 2074, 2100, 2127, 2154, 2181, 2209, 2236, 2264, 2292, 2321, 2349, 2378, 2407,
	2436, 2466, 2495, 2525, 2556, 2586, 2617, 2648, 2679, 2710, 2742, 2774, 2806, 2839, 2871, 2904,
	2937, 2971, 3004, 3038, 3072, 3107, 3141, 3176, 3212, 3247, 3283, 3319, 3355, 3392, 3428, 3465,
	3503, 3540, 3578, 3616, 3654, 3693, 3732, 3771, 3811, 3850, 3890, 3931, 3971, 4012, 4053, 4095
};
//*/
//*
const uint8_t PROGMEM PROGMEM cielab_8bit[] =
{
	0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1,   1,   1,   1,
	1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,
	3,   3,   4,   4,   4,   4,   4,   5,   5,   5,   5,   5,   6,   6,   6,   6,
	6,   7,   7,   7,   7,   8,   8,   8,   8,   9,   9,   9,   10,  10,  10,  11,
	11,  11,  12,  12,  12,  13,  13,  13,  14,  14,  14,  15,  15,  16,  16,  17,
	17,  17,  18,  18,  19,  19,  20,  20,  21,  21,  22,  22,  23,  23,  24,  24,
	25,  25,  26,  27,  27,  28,  28,  29,  30,  30,  31,  31,  32,  33,  33,  34,
	35,  35,  36,  37,  38,  38,  39,  40,  41,  41,  42,  43,  44,  45,  45,  46,
	47,  48,  49,  50,  51,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,
	62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  73,  74,  75,  76,  77,  78,
	80,  81,  82,  83,  84,  86,  87,  88,  90,  91,  92,  93,  95,  96,  98,  99,
	100, 102, 103, 105, 106, 107, 109, 110, 112, 113, 115, 116, 118, 120, 121, 123,
	124, 126, 128, 129, 131, 132, 134, 136, 138, 139, 141, 143, 145, 146, 148, 150,
	152, 154, 155, 157, 159, 161, 163, 165, 167, 169, 171, 173, 175, 177, 179, 181,
	183, 185, 187, 189, 192, 194, 196, 198, 200, 202, 205, 207, 209, 212, 214, 216,
	218, 221, 223, 226, 228, 230, 233, 235, 238, 240, 243, 245, 248, 250, 253, 255
};
//*/

int gammapow(int i)
{
	return int(pow(float(i) / 256, 2.2) * 4095);
}

void setup()
{
	Tlc.init(0);
	Serial.begin(9600);
}

uint16_t i = 0;
int a = 0;

char serial_vect[256];
uint8_t serial_count = 0;
uint16_t pos;
char text[256] = "   On peut faire defiler du texte de TOUTES LES COULEURS!!! Youpi c'est trop genial! henritonchain@gmail.com";
uint16_t len = text_width(text);

void loop()
{
	//scroll_text_smooth(10, 20);
	for (i = 0; i < 5; i++)
	{
		animation(nyan, 70, 32);
		delay_serial(500);
	}

	scroll_text();

	delay_serial(1000);
	fadePict(creeper);
	delay_serial(1000);
	fadePict(bonhomme);
	delay_serial(1000);

	for (i = 0; i < 48; i++)
	{
		Tlc.shiftRight();
		delay_serial(100);
	}

	//Tlc.clear();
	for (i = 0; i < 800; i++)
	{
		snow();
		delay_serial(20);
	}

	for (int a = 0; a < 256; a++)
	{
		circular_sine(a);
		delay_serial(50);
	}

	fadePict(pig);
	delay_serial(1000);
	fadePict(maison);
	delay_serial(1000);
	fadePict(arcenciel);
	delay_serial(1000);
	fadePict(jojo);
	delay_serial(1000);
	fadePict(zombie);
	delay_serial(1000);


}

uint16_t text_width(char *str)
{
	uint16_t len = 0;
	while (*str)
	{
		if (*str >= 32 && *str <= 126) // is printable
			len += pgm_read_byte(&font_width[(*str) - 32]);
		str++;
		len++;
	}
	return (len);
}


void show_text(char *str, uint16_t pos, uint16_t r, uint16_t g, uint16_t b)
{
	uint16_t sum = 0, oldsum = 0;
	uint8_t i, x, y;
	i = 0;
	while (str[i] && sum <= pos) // < or <= ??
	{
		oldsum = sum;
		if (str[i] >= 32 && str[i] <= 126) // is printable
			sum += pgm_read_byte(&font_width[(str[i]) - 32]);
		i++;
		sum++;
	}
	if (i > 0) i--;
	for (x = pos - oldsum; x < pgm_read_byte(&font_width[(str[i]) - 32]); x++)
	{
		for (y = 0; y < 8; y++)
		{
			if (str[i] >= 32 && str[i] <= 126)
				if (pgm_read_byte(&font[(str[i] - 32) * 8 + y]) & (1 << x))
					Tlc.setLED(7 - y, x - pos + oldsum, r, g, b);
		}
	}
	i++;
	while (str[i] && sum < pos + 8)
	{
		for (x = 0 ; x < pgm_read_byte(&font_width[(str[i]) - 32]) && x - pos + sum < 8; x++)
		{
			for (y = 0; y < 8; y++)
			{
				if (str[i] >= 32 && str[i] <= 126)
					if (pgm_read_byte(&font[(str[i] - 32) * 8 + y]) & (1 << x))
						Tlc.setLED(7 - y, x - pos + sum, r, g, b);
			}
			//x++;
			//sum++;
		}
		sum += pgm_read_byte(&font_width[(str[i]) - 32]);
		sum++;
		i++;
	}
}

void scroll_text()
{
	for (pos = 0; pos < len; pos++)
	{
		Tlc.clear();
		switch ((pos * 6) / len)
		{
		case 0:
			show_text(text, pos, 4095, pgm_read_word(&cielab_12bit[(((pos % (len / 6)) * 255) / (len / 6))]), 0);
			break;
		case 1:
			show_text(text, pos,  pgm_read_word(&cielab_12bit[255 - (((pos % (len / 6)) * 255) / (len / 6))]), 4095, 0);
			break;
		case 2:
			show_text(text, pos,	0, 4095, pgm_read_word(&cielab_12bit[(((pos % (len / 6)) * 255) / (len / 6))]));
			break;
		case 3:
			show_text(text, pos, 0, pgm_read_word(&cielab_12bit[255 - (((pos % (len / 6)) * 255) / (len / 6))]), 4095);
			break;
		case 4:
			show_text(text, pos, pgm_read_word(&cielab_12bit[(((pos % (len / 6)) * 255) / (len / 6))]), 0, 4095);
			break;
		case 5:
			show_text(text, pos, 4095, 0, pgm_read_word(&cielab_12bit[255 - (((pos % (len / 6)) * 255) / (len / 6))]));
			break;
		}
		delay_serial(70);
	}
}

void scroll_text_smooth(uint8_t steps, uint8_t delta)
{
	uint8_t step;
	for (pos = 0; pos < len; pos++)
	{
		for(step = 0 ; step < steps / 2; step++)
		{
			Tlc.clear();
			show_text(text, pos, pgm_read_word(&cielab_12bit[step * (255 / steps)]), pgm_read_word(&cielab_12bit[step * (255 / steps)]), pgm_read_word(&cielab_12bit[step * (255 / steps)]));
			show_text(text, pos - 1, pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]), pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]), pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]));
			delay_serial(delta);
		}
		for(step = steps / 2; step < steps; step++)
		{
			Tlc.clear();
			show_text(text, pos - 1, pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]), pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]), pgm_read_word(&cielab_12bit[(steps - step) * (255 / steps)]));
			show_text(text, pos, pgm_read_word(&cielab_12bit[step * (255 / steps)]), pgm_read_word(&cielab_12bit[step * (255 / steps)]), pgm_read_word(&cielab_12bit[step * (255 / steps)]));
			delay_serial(delta);
		}
	}
}

void delay_serial(uint16_t howlong)
{
	uint8_t testbyte;
	uint16_t divided = howlong;
	uint16_t i;
	for (i = 0; i < divided; i++)
	{

		while (Serial.available() > 0)
		{
			// read the incoming byte:
			serial_vect[serial_count] = Serial.read();
			//testbyte = Serial.read();
			// say what you got:
			//Serial.print("I received: ");
			//Serial.println(serial_vect[serial_count], DEC);
			//Serial.println(testbyte, DEC);
			if (serial_vect[serial_count] == '\n')
			{
				if (serial_count == 12)
				{
					Serial.println("set color");
					Tlc.setAllLED((serial_vect[0] - '0') * 1000 + (serial_vect[1] - '0') * 100 + (serial_vect[2] - '0') * 10 + serial_vect[3] - '0',
								  (serial_vect[4] - '0') * 1000 + (serial_vect[5] - '0') * 100 + (serial_vect[6] - '0') * 10 + serial_vect[7] - '0',
								  (serial_vect[8] - '0') * 1000 + (serial_vect[9] - '0') * 100 + (serial_vect[10] - '0') * 10 + serial_vect[11] - '0');
					delay_serial(1000);
				}
				else
				{
					Serial.println("set text");
					pos = 0;
					serial_vect[serial_count] = 0;
					strcpy(text, serial_vect);
					len = text_width(text);
				}
				serial_count = -1;
			}

			serial_count++;
			serial_count %= 256;

		}

		delay(1);
	}

}
void snow()
{
	int col, row;
	int previous;
	for (col = 7; col >= 0 ; col--)
	{
		for (row = 0; row < 8; row++)
		{
			if (Tlc.get(col, row) == 4095 && random(10) == 0) //only looks at red channel (lednum = col)
			{
				if (col != 0)
					Tlc.setLED(col - 1, row, 4095, 4095, 4095);
				Tlc.setLED(col, row, 0, 0, 0);
			}
		}
	}
	for (row = 0; row < 8; row++)
	{
		if (random(100) == 0)
			Tlc.setLED(7, row, 4095, 4095, 4095);
	}

}

void sine(int a)
{
	int c;
	int r;
	for (c = 0; c < 8; c++)
	{
		for (r = 0; r < 8; r++)
		{
			Tlc.setLED(c, r, pgm_read_word(&cielab_12bit[(int) (127 * (sin(3.14 * (8 * c - 2 * a) / 32) + 1))]),
					   pgm_read_word(&cielab_12bit[(int) (127 * (sin(3.14 * (8 * r - 2 * a) / 32) + 1))]),
					   pgm_read_word(&cielab_12bit[(int) (127 * (sin(3.14 * (8 * (17 - r - c) - 2 * a) / 32) + 1))]));
		}
	}
}

void circular_sine(int a)
{
	int c;
	int r;
	for (c = 0; c < 8; c++)
	{
		for (r = 0; r < 8; r++)
		{
			Tlc.setLED(c, r, pgm_read_word(&cielab_12bit[(int) (127 * (sin(3.14 * (8 * (c * c + r * r) - 8 * a) / 256) + 1))]),
					   pgm_read_word(&cielab_12bit[(int) (127 * (cos(3.14 * (8 * (( 7 - c) * ( 7 - c) + (7 - r) * (7 - r)) - 8 * a) / 256) + 1))]),
					   pgm_read_word(&cielab_12bit[(int) (127 * (cos(3.14 * (8 * ((c) * (c) + (7 - r) * (7 - r)) - 8 * a) / 256) + 1))]));
		}
	}
}

void animation(const uint8_t *pict, uint8_t delta, uint8_t frames)
{
	int a = 1;
	int order = 1;
	for (uint8_t a = 0; a < frames; a++)
	{
		for (uint8_t c = 0; c < 8; c++)
		{
			for (uint8_t r = 0; r < 8; r++)
			{
				Tlc.setLED(r, c, pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(8 * 8 * 3 ) * a + (c + (7 - r) * 8 ) * 3])]),
						   pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(8 * 8 * 3 ) * a + (c + (7 - r) * 8 ) * 3 + 1])]),
						   pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(8 * 8 * 3 ) * a + (c + (7 - r) * 8 ) * 3 + 2])]));
			}
		}
		delay_serial(delta);
	}
}

void fadePict(const uint8_t *pict)
{
	int a = 1;
	int order = 1;
	//while (a != 0)
	//{
	for (int c = 0; c < 8; c++)
	{
		for (int r = 0; r < 8; r++)
		{
			Tlc.setLED(r, c, pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(c + (7 - r) * 8 ) * 3])]),
					   pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(c + (7 - r) * 8 ) * 3 + 1])]),
					   pgm_read_word(&cielab_12bit[pgm_read_byte(&pict[(c + (7 - r) * 8 ) * 3 + 2])]));
			//Tlc.setLED(r,4095,
			//4095,
			//4095);
			//Tlc.setLED(r, pict[(c + (7 - r) * 8 )* 3] * 16,
			//			  pict[(c + (7 - r) * 8 )* 3 + 1] * 16,
			//			  pict[(c + (7 - r) * 8 )* 3 + 2] * 16);
		}
		//Tlc.update(c);
		//setColumn(c);
		//Tlc.setRow(c);
	}
	// a += order;
	//if (a == 512) order = -order;
	//}
}
//*/
/*
int channel = 0;
int direction = 1;
void loop()
{
	Tlc.clear();
	//Tlc.set(channel, 1000);
	Tlc.setLED(channel, 1000, 1000, 1000);
		Tlc.update();

	channel += direction;
	if (channel == 8 ) {
	  channel = 0;
	}


	delay_serial(500);

}
*/
