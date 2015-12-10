IFCMD(inc)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = INC_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(dec)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = DEC_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(mov)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MOV_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MOV_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(add)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = ADD_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = ADD_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(sub)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SUB_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SUB_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(mul)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MUL_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MUL_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(div)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = DIV_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = DIV_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(mod)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MOD_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = MOD_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(and)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = AND_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = AND_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(nand)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = NAND_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = NAND_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(or)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = OR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = OR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(nor)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = NOR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = NOR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(xor)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = XOR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = XOR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(xnor)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = XNOR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = XNOR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(not)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = NOT_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(shl)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SHL_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SHL_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(shr)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SHR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SHR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(rtl)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = RTL_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = RTL_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(rtr)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NUM)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = RTR_REG_NUM;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = atoi(arg2);
			return 0;
		}
	}
	if (arg1Type == REG)
	{
		if (arg2Type == REG)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = RTR_REG_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			NEXT_COMMAND = REG_NUM(arg2);
			return 0;
		}
	}
}

IFCMD(push)
{
	if (arg1Type == NUM)
	{
		CHECK_PROGRAM_SIZE(2);
		NEXT_COMMAND = PUSH_NUM;
		NEXT_COMMAND = atoi(arg1);
		return 0;
	}
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = PUSH_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(pop)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = POP;
		return 0;
	}
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = POP_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(sinc)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SINC;
		return 0;
	}
}

IFCMD(sdec)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SDEC;
		return 0;
	}
}

IFCMD(smov)
{
	if (arg1Type == REG)
	{
		if (arg2Type == NONE)
		{
			CHECK_PROGRAM_SIZE(3);
			NEXT_COMMAND = SMOV_REG;
			NEXT_COMMAND = REG_NUM(arg1);
			return 0;
		}
	}
}

IFCMD(sadd)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SADD;
		return 0;
	}
}

IFCMD(ssub)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SSUB;
		return 0;
	}
}

IFCMD(smul)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SMUL;
		return 0;
	}
}

IFCMD(sdiv)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SDIV;
		return 0;
	}
}

IFCMD(smod)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SMOD;
		return 0;
	}
}

IFCMD(sand)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SAND;
		return 0;
	}
}

IFCMD(snand)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SNAND;
		return 0;
	}
}

IFCMD(sor)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SOR;
		return 0;
	}
}

IFCMD(snor)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SNOR;
		return 0;
	}
}

IFCMD(sxor)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SXOR;
		return 0;
	}
}

IFCMD(sxnor)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SXNOR;
		return 0;
	}
}

IFCMD(snot)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SNOT;
		return 0;
	}
}

IFCMD(sshl)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SSHL;
		return 0;
	}
}

IFCMD(sshr)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SSHR;
		return 0;
	}
}

IFCMD(srtl)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SRTL;
		return 0;
	}
}

IFCMD(srtr)
{
	if (arg1Type == NONE)
	{
		CHECK_PROGRAM_SIZE(1);
		NEXT_COMMAND = SRTR;
		return 0;
	}
}