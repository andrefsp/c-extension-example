package main

// #include <xyzzy.h>
import "C"
import "fmt"

func custom_str_len(quote string) int {
	// Bind to custom.h  custom_str_len() method
	return int(C.custom_str_len(C.CString(quote)))
}

func custom_str(quote string) string {
	return C.GoString(C.custom_str(C.CString(quote)))
}

func main() {
	quote := "andre filipe"
	fmt.Println(">>> ", custom_str_len(quote))
	fmt.Println(">>> ", custom_str(quote))
}
