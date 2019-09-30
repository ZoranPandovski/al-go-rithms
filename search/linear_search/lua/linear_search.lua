return
{
    linear_search = function(table, value)

        -- Iterate through list until item is found
        for i = 1, #table do
            if table[i] == value then
                return i
            end
        end

        -- Return nil if not found
        return nil
    end
}