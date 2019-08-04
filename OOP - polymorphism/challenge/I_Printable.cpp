#include "I_Printable.h"

std::ostream& operator<<(std::ostream& os, I_Printable const& rhs)
{
	rhs.print(os); // BECAUSE THAT RHS OBJECT HAS ALREADY OVERRIDEN PRINT (IT MUST HAVE SINCE PRINT WAS PURE VIRTUAL)  SO WE CAN SIMLY CALL THAT FUNCTION WITH REFERENCE TO OUTPUT STREAM AS PARAMETER
	return os;
}
