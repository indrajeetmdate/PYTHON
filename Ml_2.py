import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Define the independent variables (features) and the target variable (Y)
X = data.drop(columns=['hydrogen wt. % storage'])
Y = data['hydrogen wt. % storage']

# Split the data into training and testing sets (e.g., 80% train, 20% test)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=42)

# Create a linear regression model
model = LinearRegression()

# Fit the model to the training data
model.fit(X_train, Y_train)

# Make predictions on the test data
Y_pred = model.predict(X_test)

# Calculate Mean Squared Error (MSE)
mse = mean_squared_error(Y_test, Y_pred)

# Calculate R-squared (R2) to assess the goodness of fit
r2 = r2_score(Y_test, Y_pred)

print(f'Mean Squared Error: {mse}')
print(f'R-squared (R2): {r2}')

 making a prediction on new data
new_data = np.array([[value1, value2, value3])
predicted_value = model.predict(new_data)
print(f'Predicted hydrogen wt. % storage: {predicted_value[0]}')
