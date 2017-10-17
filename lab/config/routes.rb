Rails.application.routes.draw do
 get 'signup'  => 'users#new' 
  resources :users
 get 'show'  => 'users#index' 

end
