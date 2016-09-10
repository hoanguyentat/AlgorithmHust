%% functionname: function description
function [cnt vector] = primares(n)
	k = sqrt(n);
	for i= 1 : n 
		check = false;
		for j = 2 : k
			if (i  j == 0)
			 	check = true;
			 end
		end 
		if check == false
			vector = [vector, i];
		end
	end
	cnt = length(vector);
end