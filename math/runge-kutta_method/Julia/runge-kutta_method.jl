function runge_kutta(y0::Float64, t0::Float64, h::Float64, steps::Int, func::AbstractString)
    result = Float64[]
    t_array = Float64[]
    expression = parse(func)
    global y = y0
    global t = t0
    push!(result, y0)
    push!(t_array, t0)
    
    for i = 2:(steps+1)
        tn = t
        kn1 = eval(expression)
        t = tn + h/2
        y = result[i-1] + kn1*h/2
        kn2 = eval(expression)
        t = tn + h/2
        y = result[i-1] + kn2*h/2
        kn3 = eval(expression)
        t = tn + h
        y = result[i-1] + kn3*h
        kn4 = eval(expression)
        push!(result,result[i-1] + ((kn1+2*kn2+2kn3+kn4)/6)*h)
        
        t = tn+h
        push!(t_array, t)
        y = result[i];
    end
    return result, t_array
end

result, t_array = runge_kutta(0.0, 0.0, 0.1, 20, "1+2t")
for i in result
	println(i)
end
