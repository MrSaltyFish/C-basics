// Space: https://youtu.be/n-S9DBwPGTo
//  Upto 19:27 - Adjusted nob for isSpace() -
//

#include <stdio.h>

#define NOB_IMPLEMENTATION
#include "nob.h"

int main() {
	const char *file_path = "t8.shakespeare.txt";
	Nob_String_Builder buf = {0};
	if (!nob_read_entire_file(file_path, &buf)) return 1;

	nob_log(NOB_INFO, "Size of %s is %zu bytes", file_path, buf.count);

	Nob_String_View content = {
		.data = buf.items,
		.count = buf.count,
	};

	for (size_t i = 0; i < 1 && content.count > 0; i++) {
		Nob_String_View token = nob_sv_chop_by_space(&content);
		nob_log(NOB_INFO, "   " SV_Fmt, SV_Arg(token));
	}

	return 0;
}