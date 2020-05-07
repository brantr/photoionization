EXEC   = photoionization

OPTIMIZE += $(OPTS)

OBJS   = main.o photoionization.o

CC     = g++

INCL   = photoionization.h

LIBS   = -lm -lgsl -lgslcblas 


CFLAGS  = $(OPTIMIZE) 
LDFLAGS = 

$(EXEC): $(OBJS) 
	 $(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(EXEC)   

$(OBJS): $(INCL) 

.PHONY : clean

clean:
	 rm -f $(OBJS) $(EXEC)

